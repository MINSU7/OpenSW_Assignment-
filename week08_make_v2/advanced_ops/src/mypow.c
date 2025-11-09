#include "advanced_ops.h"

double mypow(int a, int b){
    int cnt = 1;
    for(int i = 0; i < b;i++){
        cnt *= a;
    }
    return cnt;
}