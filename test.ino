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
char font1[MATRIX_LEN] = {0x00,0x02,0x04,0x08,0x78,0x08,0x08,0x08};
// char font1[MATRIX_LEN] = {0x00,0x7e,0x02,0x14,0x18,0x10,0x10,0x20};
char getDigitNum(char,char);

void setup(){
    for(int i=1; i<17; i++){
        pinMode(pinNum[i], OUTPUT); 
    }
    for(int i=1; i<MATRIX_LEN; i++){
        digitalWrite(pinNum[row[i]], LOW); 
    }
    printf("%d",getDigitNum(font1[0],1));
}

void loop(){
    // digitalWrite(pinNum[col[0]],HIGH);
    // カウンタの処理
    if(count == 0){
        count = 1;
    }
    else{
        count = 0;
    }

    // // LEDを一部だけ点灯させる
    // // 行ごとに点灯状況を変える
    // // for(int i=0; i<MATRIX_LEN; i++){
    // //     if(i%2 == count){
    // //         digitalWrite(pinNum[row[i]],HIGH);
    // //     }
    // //     else{
    // //         digitalWrite(pinNum[row[i]],LOW);
    // //     }
    // //     // 列ごとに点灯状況を変える
    // //     for(int j=0; j<MATRIX_LEN; j++){
    // //         // digitalWrite(pinNum[row[3]],LOW);
    // //         if(j%2 == count){
    // //             digitalWrite(pinNum[col[j]],HIGH);
    // //         }
    // //         else{
    // //             digitalWrite(pinNum[col[j]],LOW);           
    // //         }
    // //         // delay(1);
    // //     }
    // //     // delay(1);
    // // }

    // 文字を表示する
    for(int i=0; i<MATRIX_LEN; i++){
        // LEDの点灯状態を初期化
        for(int j=0; j<MATRIX_LEN; j++){
            digitalWrite(pinNum[row[j]],LOW);
            digitalWrite(pinNum[col[j]],LOW);
        }

        delay(0.5); // 画面を全消去する時間を設ける

        digitalWrite(pinNum[row[i]],HIGH);
        
        for(int j=0; j<MATRIX_LEN; j++){

            if(getDigitNum(font1[i],j) == 1){
                digitalWrite(pinNum[col[j]],LOW);
            }
            else{
                digitalWrite(pinNum[col[j]],HIGH);          
            }
        }
        delay(2.5);
    }

    delay(2.5);
}

// フォントの各行の各要素の値を調べる
char getDigitNum(char num, char col){
    // 目的の桁だけを&シフト演算で取り出し、ずらした分を元に戻すと1か0が出てくる
    // 列は左から数えていることに注意
    return ((num & (00000001 << MATRIX_LEN-col-1)) >> MATRIX_LEN-col-1);
}
