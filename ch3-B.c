#include <stdio.h>

const int prices[5] = {160, 120, 130, 140, 150}; // 商品の価格：牛乳、麦茶、緑茶、コーヒー、紅茶
const int money_kind[5] = {1000,500,100,50,10};
#define numofMK (sizeof(money_kind)/sizeof(money_kind[0])) //money_kindの要素数

int generate_ouput_money(int* result, int* envelopes,int price){
    //出力する硬貨の枚数をresult配列によって表現する関数
    //result＝結果の配列,envelopes=使用可能な硬貨の枚数の配列,price＝出力する金額
    int i = 0;
    for(i = 0; i < numofMK;i++)
        printf("%d,",envelopes[i]);
        printf("\n");
    while (1){
        int tempcoin = price - money_kind[i];//引いてみる
        if(tempcoin > 0 && envelopes[i] >= 1){
            envelopes[i]--;
            result[i]++;
            result -= money_kind[i];
        }else if (tempcoin == 0 && envelopes[i] >= 1)
        {
            envelopes[i]--;
            result[i]++;
            break;
        }else if (i == numofMK-1 && envelopes[numofMK-1] == 0)//envelopes[numofMK-1]は十円玉の枚数
        {
            return -1;
        }
        else if (i == numofMK){
            printf("投入金額が足りません。\n");
            break;
        }else{//tempcoin < 0 
            i++;
        }
    }
    return 0;
}

int main()
{
    int envelopes[5] = {1, 5, 5, 5, 5}; // 封筒(枚数)：千円札、五百円玉、百円玉、五十円玉、十円玉
    int shelf[5] = {4, 4, 4, 4, 4}; // 商品棚：各飲料の在庫は4本
    
    while (1)
    {
        int i;

        printf("0:牛乳160円, 1:麦茶120円, 2:緑茶130円, 3:コーヒー140円, 4:紅茶150円\n");
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

        

        int buf_envelopes[5] = {0}; //硬貨がなかった時用に別に保存しておく
        for(i = 0; i < sizeof(buf_envelopes)/sizeof(int); i++)
            buf_envelopes[i] = envelopes[i];

        printf("要求金額:%d円\nお金を投入してください.\n", prices[choice]);
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

        int ouput[5] = {0};
        int flg_lack = generate_ouput_money(ouput,envelopes,chenge);
        printf("%d\n",flg_lack);

        for(i = 0; i < sizeof(ouput)/sizeof(int);i++){
            printf("ouput_money[%d]:%d\n",i,ouput[i]);
        }

        for(i = 0; i < sizeof(envelopes)/sizeof(int);i++){
            printf("envelopes[%d]:%d\n",i,envelopes[i]);
        }
        
    }
    
    

    return 0;
}
