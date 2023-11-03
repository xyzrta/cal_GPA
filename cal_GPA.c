#include <stdio.h>
#define SIZE 256    //このプログラムで計算できる科目数上限

int Convert_to_GP(int score){
    if(90 <= score && score <= 100){
        return 4;
    }
    else if(80 <= score && score <= 89){
        return 3;
    }
    else if(70 <= score && score <= 79){
        return 2;
    }
    else if(60 <= score && score <= 69){
        return 1;
    }
    else if(0 <= score && score <= 59){
        return 0;
    }else{
        return -1;
    }
}

void GPA(int k,int n,int s[],int t[]){
    for(int i = 0; i < k; i++){
        s[i] = Convert_to_GP(s[i]);
    }

    int sum = 0;
    for(int i = 0; i < k; i++){//(単位数*GP)の和を計算しsumに代入
        sum += t[i]*s[i];
    }
    double gpa = (double)sum/n;

    printf("あなたのGPAは %.2lf です。\n",gpa);
}

int main(){

    char file_name[256];
    int score[SIZE],credit[SIZE];
    FILE *fp;

    printf("GPAを計算します。\n成績表のファイル名(.txt)を入力してください。\n");
    printf("成績表のファイル(.txt)を半角アルファベットで拡張子付きで入力 => ");
    scanf("%s",file_name);

    if((fp = fopen(file_name,"r")) == NULL){
        printf("\aエラー：このファイルは開けません。\n");
    }else{
        int i = 0;
        int sum = 0;
        while(fscanf(fp, "%d,%d" ,&score[i], &credit[i]) == 2 && i < SIZE){
            sum += credit[i];
            i++;
        }
        int subject_num = i;
        int credit_num = sum;
        GPA(subject_num,credit_num,score,credit);
        fclose(fp);
    }
    return 0;
}
