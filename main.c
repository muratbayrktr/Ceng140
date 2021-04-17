#include <stdio.h>

float try_btc = 0.0555;
float btc_try = 18.0180;
float try_eth = 0.0833;
float eth_try = 12.0048;
float btc_eth = 1.5001;
float eth_btc = 0.6666;

/* quits the programme */
int quit()
{
    printf("Bye...\n");
    return 0;
}

/* prints out the current wallet status */
int read(float try, float btc, float eth) 
{
    if ((btc != 0.0) && (eth == 0.0)) {
        printf("Our account holds %.2f TRY | %.2f BTC.\n",try,btc);
    } else if ((btc == 0.0) && (eth != 0.0)) {
        printf("Our account holds %.2f TRY | %.2f ETH.\n",try,eth);
    } else if ((btc != 0.0) && (eth != 0.0)) {
        printf("Our account holds %.2f TRY | %.2f BTC | %.2f ETH.\n",try,btc,eth);
    } else {
        printf("Our account holds %.2f TRY.\n",try);
    }
    return 0;
}

/*  deposit money to the wallet with given type of currency */
void deposit(float* try, float* btc, float* eth) 
{
    float bridge = 0;
    char coin_type;
    scanf(" %c %f",&coin_type,&bridge);
    if (coin_type == 'B') 
    {
        *btc += bridge;
    } else if (coin_type == 'E') {
        *eth += bridge;
    } else if (coin_type == 'T') {
        *try += bridge;
    } else {
        printf("Error: Operation could not be completed.\n");
    }
    return ;
}

/* withdraw money from the given type of currency */
void withdraw(float* try, float* btc, float* eth)
{
    float bridge = 0;
    char coin_type;
    scanf(" %c %f",&coin_type,&bridge);
    if (coin_type == 'B') 
    {   /* checking error status */
        if (*btc >= bridge) *btc -= bridge;
        else printf("Error: Insufficient funds.\n");
    } else if (coin_type == 'E') {
        if (*eth >= bridge) *eth -= bridge;
        else printf("Error: Insufficient funds.\n");
    } else if (coin_type == 'T') {
        if (*try >= bridge) *try -= bridge;
        else printf("Error: Insufficient funds.\n");
    } else { 
        printf("Error: Operation could not be completed.\n");
    }
    return ; 
}

/* exchange currencies among each other */
void exchange(float* try, float* btc, float* eth)
{
    float bridge,transform;
    char selling_currency, buying_currency;
    scanf(" %c %f %c",&selling_currency,&bridge,&buying_currency);
    /* checking error status */
    if ((selling_currency != 'T' && selling_currency != 'B' && selling_currency != 'E') || 
        (buying_currency != 'T' && buying_currency != 'B' && buying_currency != 'E') ) {
        printf("Error: Operation could not be completed.\n");
    } else if (selling_currency == 'T' && buying_currency == 'B') {
         if (bridge > *try) {
            int i = 1;
            while (1) {
                transform = btc_try*i;
                if (transform > *try) {
                    *btc += (i-1);
                    *try -= btc_try*(i-1);
                    break;
                }
                i++;
            }
            printf("This amount is too much, you have successfully bought %.2f BTC.\n",(float) i-1);
        } else {
            printf("You have successfully bought %.2f BTC.\n",try_btc*bridge);
            *btc += try_btc*bridge;
            *try -= bridge;
        }
    
    } else if (selling_currency == 'B' && buying_currency == 'T') {
         if (bridge > *btc) {
            int i = 1;
            while (1) {
                transform = try_btc*i;
                if (transform > *btc) {
                    *try += (i-1);
                    *btc -= try_btc*(i-1);
                    break;
                }
                i++;
            }
            printf("This amount is too much, you have successfully bought %.2f TRY.\n",(float) i-1);
        } else {
            printf("You have successfully bought %.2f TRY.\n",btc_try*bridge);
            *try += btc_try*bridge;
            *btc -= bridge;
        }
    
    } else if (selling_currency == 'T' && buying_currency == 'E') {
         if (bridge > *try) {
            int i = 1;
            while (1) {
                transform = eth_try*i;
                if (transform > *try) {
                    *eth += (i-1);
                    *try -= eth_try*(i-1);
                    break;
                }
                i++;
            }
            printf("This amount is too much, you have successfully bought %.2f ETH.\n",(float) i-1);
        } else {
            printf("You have successfully bought %.2f ETH.\n",try_eth*bridge);
            *eth += try_eth*bridge;
            *try -= bridge;
        }       
    
    } else if (selling_currency == 'E' && buying_currency == 'T') {
         if (bridge > *eth) {
            int i = 1;
            while (1) {
                transform = try_eth*i;
                if (transform > *eth) {
                    *try += (i-1);
                    *eth -= try_eth*(i-1);
                    break;
                }
                i++;
            }
            printf("This amount is too much, you have successfully bought %.2f TRY.\n",(float) i-1);
        } else {
            printf("You have successfully bought %.2f TRY.\n",eth_try*bridge);
            *try += eth_try*bridge;
            *eth -= bridge;
        }  
        
    } else if (selling_currency == 'B' && buying_currency == 'E') {
        if (bridge > *btc) {
            int i = 1;
            while (1) {
                transform = eth_btc*i;
                if (transform > *btc) {
                    *eth += (i-1);
                    *btc -= eth_btc*(i-1);
                    break;
                }
                i++;
            }
            printf("This amount is too much, you have successfully bought %.2f ETH.\n",(float) i-1);
        } else {
            printf("You have successfully bought %.2f ETH.\n",btc_eth*bridge);
            *eth += btc_eth*bridge;
            *btc -= bridge;            
        }

    } else if (selling_currency == 'E' && buying_currency == 'B') {
        if (bridge > *eth) {
            int i = 1;
            while (1) {
                transform = btc_eth*i;
                if (transform > *eth) {
                    *btc += (i-1);
                    *eth -= btc_eth*(i-1);
                    break;
                }
                i++;
            }
            printf("This amount is too much, you have successfully bought %.2f BTC.\n",(float) i-1);
        } else {
            printf("You have successfully bought %.2f BTC.\n",eth_btc*bridge);
            *btc += eth_btc*bridge;
            *eth -= bridge;            
        }     
    }
}

/* suggestion function for exploring gains according to the loss percentage and expected gain */
void suggest(float* try, float* btc, float* eth, float amount)
{
    char coin1, coin2, suggestion;
    int loss_per1, exp_gain1, loss_per2, exp_gain2;
    float gain1,gain2,gain;

    suggestion = 'N';

    scanf(" %c %d %d %c %d %d",&coin1,&loss_per1,&exp_gain1,&coin2,&loss_per2,&exp_gain2);
    
    if ((coin1 != 'E' && coin1 != 'B') || (coin2 != 'E' && coin2 != 'B')) {
        printf("Error: Operation could not be completed.\n");
        return ;
    }
    
    gain1 = (((amount - amount*loss_per1*0.01)*(1+exp_gain1*0.01))*(1-loss_per1*0.01))-amount;
    gain2 = (((amount - amount*loss_per2*0.01)*(1+exp_gain2*0.01))*(1-loss_per2*0.01))-amount;

    if (gain1 < 0 && gain2 < 0) {
        printf("Trading currently is not logical.\n");
    } else {
        suggestion = (gain1 > gain2) ? (coin1) : (coin2);
        gain = (gain1 > gain2) ? (gain1) : (gain2);
    }


    if (suggestion == 'E') {
        *eth += try_eth*amount;
        *try -= amount;
        printf("%s is better with %.2f TRY gain. Buying it...\n", (suggestion == 'E') ? "ETH" : "BTC",gain);
    }
    if (suggestion == 'B') {
        *btc += try_btc*amount;
        *try -= amount;        
        printf("%s is better with %.2f TRY gain. Buying it...\n", (suggestion == 'E') ? "ETH" : "BTC",gain);
    }
    return ;
}

/* main flow */
int main()
{
    /* function declarations */
    int quit();
    void deposit(),withdraw(),exchange();
    void suggest(float *try, float* btc, float* eth, float bridge);
    int read(float try, float btc, float eth);

    /* variable declarations */
    char op_code;
    float try, btc, eth;
    float bridge = 0.;

    /* initially set currencies to zero */
    try = btc = eth = 0;
    scanf("%c %f",&op_code,&try);

    /* error check */
    if (op_code != 'T') {
        printf("Error: Operation could not be completed.");
        return 0;
    }
    /* unless there is a quit command continue executing */
    do
    {   /* get the op code and execute according function */
        op_code = getchar();
        switch(op_code)
        {
            case 'T': 
            {
                scanf(" %f",&bridge); 
                try += bridge;
                break;
            }
            case 'Q': 
            {
                quit(); 
                break;
            }
            case 'R': 
            {
                read(try,btc,eth); 
                break;
            }
            case 'D': 
            {
                deposit( &try, &btc, &eth);
                break;
            }
            case 'W': 
            {
                withdraw( &try, &btc, &eth);
                break;
            }
            case 'X': 
            {
                exchange(&try, &btc, &eth);
                break;
            }
            case 'S': 
            {
                scanf(" %f",&bridge);
                if (bridge > try) {
                    printf("Error: Operation could not be completed.\n");
                    break;
                }
                suggest(&try, &btc, &eth, bridge);
                break;
            }
        } 

    } while (op_code != 'Q');
    return 0;
}