///*
//* C Program to print full pyramid pattern using *
//*/
//#include<stdio.h>
//#include<conio.h>
//int main() {
//    int row, space, rows, star=0;
//    printf("Enter the number of rows in reverse pyramid\n");
//    scanf("%d",&rows);
// 
//    for(row = rows;row >= 1; row--) {
//     /* Printing spaces */
//        for(space = 0; space <= rows-row; space++) {
//           printf("  ");
//        }
//        /* Printing stars */
//        star = 0;
//        while(star != (2*row - 1)) {
//            printf("* ");
//            star++;
//        }
//        printf("\n");
//    }
//    getch();
//    return 0;
//}