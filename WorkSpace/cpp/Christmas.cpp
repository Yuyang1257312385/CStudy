
#include <stdio.h>
#include <stdlib.h>
#include <cstdlib>
#include <unistd.h>
#include <string.h>



#include <iostream>

using namespace std;
 
int main(void)
{

    int loop = 0;
    for(;loop < 100;loop++){
    
        if(loop % 16 == 1){
            system("color F1");
        }else if(loop %16 == 2){
            system("color F1");
        }else if(loop %16 == 3){
            system("color F1");
        }else if(loop %16 == 4){
            system("color F3");
        }else if(loop %16 == 5){
            system("color F3");
        }else if(loop %16 == 6){
            system("color F3");
        }else if(loop %16 == 7){
            system("color F5");
        }else if(loop %16 == 8){
            system("color F5");
        }else if(loop %16 == 9){
            system("color F5");
        }else if(loop %16 == 10){
            system("color F9");
        }else if(loop %16 == 11){
            system("color F9");
        }else if(loop %16 == 12){
            system("color F9");
        }

        int i = 0;
        int j = 0;
        int x = 0;
        int n = 0;
        // a是间隔填充物，这里用空白填充；b是雪花，这里用*表示；c是圣诞树的填充，用'0'表示 
        char a = ' ', b = '*', c = '0';
        // 第一部分，输出树叶
        for (; x < 3; x++) {
            // 想让圣诞树变高可以将4这个值调高 
            for (i = 0; i < x + 4; i++) {
                for (j = 0; j < 80; j++) {
                    if ((j <= 25 + n) && (j >= 25 - n)) {
                        printf("%c", c);
                    } else if ((j % (n + 6) == n) && ( (j > 25 + n) || (j < 25 - n))) {
                        int random = rand();
                        if(random%2 == 0){
                            printf("%c", b);
                        }
                        printf("%c", b);
                    } else {
                        printf("%c", a);
                    }  
                }
                printf("\n");
                n = n + 2;
            }
            n = n - 2 * (x + 2);
        }
        // 第二部分，输出树干，高度为5 
        for (i = 0; i < 5; i++) {
            for (j = 0; j < 80; j++) {
                if (j >= 22 && j <= 28) {
                    printf("%c", c);
                } else if ((j % (n + 6) == n) && ((j > 25 + n) || (j < 25 - n))) {
                    printf("%c", b);
                } else {
                    printf("%c", a);
                }   
            }
            n = n + 2;
            printf("\n");
        }
        // 第三部分，输出地面，高度为3 
        for (i = 0; i < 3; i++) {
            for (j = 0; j < 80; j++) {
                if (j % 2 == 0) {
                    printf("%c", b);
                } else {
                    printf("%c", a);
                }
                    
            }
            printf("\n");
        }

        system("cls");
    }
    

    int exit;
    cout << "input anything" << endl;
    cin >> exit;

    return 0;
}