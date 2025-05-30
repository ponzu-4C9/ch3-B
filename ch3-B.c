#include <stdio.h>

int main()
{
    int envelopes[5] = {1, 5, 5, 5, 5}; // 封筒：千円札1枚、五百円玉5枚、百円玉5枚、五十円玉5枚、十円玉5枚
    int shelf[5] = {4, 4, 4, 4, 4}; // 商品棚：各飲料の在庫は4本
    int prices[5] = {160, 120, 130, 140, 150}; // 商品の価格：牛乳1円、麦茶2円、緑茶3円、コーヒー4円、紅茶5円
    int money_kind[5] = {1000,500,100,50,10};
    
    while (1)
    {
        printf("0:牛乳, 1:麦茶, 2:緑茶, 3:コーヒー, 4:紅茶\n");
        printf("何を買う？ int>>");
        int choice;
        scanf("%d", &choice);
        if (choice < 0 || choice > 4) {
            printf("無効な選択です。\n");
            return 1;
        }
        if (shelf[choice] <= 0) {
            printf("在庫がありません。\n");
            continue;
        }

        printf("要求金額:%d円\nお金を投入してください.\n", prices[choice]);
        int i;
        int input_money[5] = {0};
        for(i = 0; i < sizeof(money_kind)/sizeof(int);i++){
            printf("%d-->",money_kind[i]);
            scanf("%d",&input_money[i]);//input_moneyに書き込み
            envelopes[i] += input_money[i]; //封筒に硬貨を入れる
        }
        int sum = 0;
        for(i = 0; i < sizeof(money_kind)/sizeof(int);i++){
            sum += money_kind[i] * input_money[i];
        }
        printf("投入金額:%d円\n",sum);
        int chenge = sum - prices[choice];
        printf("おつり:%d円\n",chenge);

        int j = 0;
        int ouput_money[5] = {0};
        while (1)
        {
            int tempcoin = chenge - money_kind[j];
            if(tempcoin > 0 && envelopes[j] >= 1){
                envelopes[j]--;
                ouput_money[j]++;
                chenge = chenge - money_kind[j];
            }else if (tempcoin == 0 && envelopes[j] >= 1)
            {
                envelopes[j]--;
                ouput_money[j]++;
                break;

            }else{//tempcoin < 0 
                j++;
                continue;
            }
            
        }
        int k;
        for(k = 0; k < sizeof(ouput_money)/sizeof(int);k++){
            printf("ouput_money:%d\n",ouput_money[k]);
        }

        for(k = 0; k < sizeof(envelopes)/sizeof(int);k++){
            printf("envelopes:%d\n",envelopes[k]);
        }
        
    }
    
    

    return 0;
}
