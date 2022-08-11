//
// #include "data.h"
#include <Arduino.h>
// #include "data.ino"
// LEDの切り欠きを下にして反時計回りに1~16
// const char pinNum[16] = {2,3,4,5,6,7,8,9, 10,11,12,13,14,15,16,17};
// 0番目は参照しない
const char pinNum[17] = {0, 2,3,4,5,6,7,8,9, 10,11,12,13,14,15,16,17};
// const char ledNum[16] = {12, 2, 3, 4, 5, 6};
const char col[8] = {13, 3, 4, 10, 6, 11, 15, 16};
const char row[8] = {9, 14, 8, 12, 1, 7, 2, 5};

const char MATRIX_LEN = 8;

int count = 0;
// int ledNum = 13;
int interval = 1000;

// 表示するフォントを作る
char font1[MATRIX_LEN] = {0x81,0x42,0x24,0x18,0x18,0x24,0x42,0x81};
char getDigitNum(char,char);

void setup(){
    for(int i=0; i<17; i++){
        pinMode(pinNum[i], OUTPUT); 
    }
    for(int i=1; i<MATRIX_LEN; i++){
        digitalWrite(pinNum[row[i]], LOW); 
    }
    printf("%d",getDigitNum(font1[0],1));
}

void loop(){
    // カウンタの処理
    if(count == 0){
        count = 1;
    }
    else{
        count = 0;
    }

    // LEDを一部だけ点灯させる
    // 行ごとに点灯状況を変える
    // for(int i=0; i<MATRIX_LEN; i++){
    //     if(i%2 == count){
    //         digitalWrite(pinNum[row[i]],HIGH);
    //     }
    //     else{
    //         digitalWrite(pinNum[row[i]],LOW);
    //     }

    //     // 列ごとに点灯状況を変える
    //     for(int j=0; j<MATRIX_LEN; j++){
    //         // digitalWrite(pinNum[row[3]],LOW);

    //         if(j%2 == count){
    //             digitalWrite(pinNum[col[j]],HIGH);
    //         }
    //         else{
    //             digitalWrite(pinNum[col[j]],LOW);           
    //         }
    //         // delay(1);
    //     }
    //     // delay(1);
    // }

    // 文字を表示する
    for(int i=0; i<MATRIX_LEN; i++){

        // 列ごとに点灯状況を変える
        for(char j=0; j<MATRIX_LEN; j++){

            if (i==0){
                digitalWrite(pinNum[row[0]],LOW);
                if(j%2 == count){
                    digitalWrite(pinNum[col[j]],HIGH);
                }
                else{
                    digitalWrite(pinNum[col[j]],LOW);           
                }
            }
            else if(i == 1){
                digitalWrite(pinNum[row[1]],LOW);
                if(j%2 != count){
                    digitalWrite(pinNum[col[j]],HIGH);
                }
                else{
                    digitalWrite(pinNum[col[j]],LOW);           
                }
            }

            // if(getDigitNum(font1[0],0) == 1){
            //     digitalWrite(pinNum[col[j]],HIGH);
            // }
            // else{
            //     digitalWrite(pinNum[col[j]],LOW);          
            // }
            if(i == 0 && j == 0){
                digitalWrite(pinNum[col[j]],HIGH);
            }
            else{
                digitalWrite(pinNum[col[j]],LOW);          
            }
 
        }
        delay(3);
    }

    // delay(3);
}

// フォントの各行の各要素の値を調べる
char getDigitNum(char num, char col){
    // 目的の桁だけを&シフト演算で取り出し、ずらした分を元に戻すと1か0が出てくる
    // 列は左から数えていることに注意
    return (num & (0000001 << MATRIX_LEN-col)) >> col;
}
