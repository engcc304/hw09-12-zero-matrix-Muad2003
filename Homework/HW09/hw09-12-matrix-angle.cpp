/*
    ผู้ใช้กรอกค่า Matrix แบบลูกบาศก์ลงใน Matrix พร้อมกับบรรจุค่าลงไปจนครบ และแสดงค่าภายใน Matrix ... จากนั้นรับค่าการแสดงผลการเปลี่ยนแปลง Matrix โดยหากรับค่า 1 จากผู้ใช้ ให้แสดงด้านมุมซ้ายของ Matrix ด้วยเลข 0 ... หากผู้ใช้กรอก -1 ให้แสดงมุมขวาของ Matrix ด้วยเลขศูนย์ (ดูตัวอย่างการแสดงผลได้ใน Test Case)
    
    Test case:
        Input cube size : 
            3
        Input element :
            1 2 3
            4 5 6
            7 8 9
        Show zero (1=Left, -1=Right) :
            1
    Output:
        Matrix =
            1 2 3
            4 5 6
            7 8 9
        Left Matrix =
            1 2 3
            0 5 6
            0 0 9

    Test case:
        Input cube size : 
            4
        Input element :
            1 2 3 3
            2 5 9 9
            7 5 3 4
            2 1 3 1
        Show zero (1=Left, -1=Right) :
            -1
    Output:
        Matrix =
            1 2 3 3
            2 5 9 9
            7 5 3 4
            2 1 3 1
        Left Matrix =
            1 0 0 0
            2 5 0 0
            7 5 3 0
            2 1 3 1
*/

#include <stdio.h>

int main() {

    int n ;
    printf ( "Input cube size : \n" ) ;
    scanf ( "%d", &n ) ;
    int leftmatrix[ n ] [ n ] ;

    // สร้างลูกบาศ
    int cube[ n ] [ n ] ;
    for ( int i = 0 ; i < n ; i++ ) {
        for ( int k = 0 ; k < n ; k++ ) {
            scanf ( "%d", &cube[ i ] [ k ] ) ;
        } // end for
    } // end for

    // สร้างทางเลือก
    int choise ;
    printf ( "Show zero (1=Left, -1=Right) :\n" ) ;
    scanf ( "%d", &choise ) ;
    

    // แสดงค่า
    printf ( "Matrix =\n" ) ;
    for ( int i = 0 ; i < n ; i++ ) {
        for ( int k = 0 ; k < n ; k++ ) {
            printf ( "%d", cube[ i ] [ k ] ) ;
            leftmatrix[ i ] [ k ] = cube[ i ] [ k ] ;
            if ( k + 1 < n ) {
                printf ( " " ) ;
            } // end if
        } // end for
        printf ( "\n" ) ;
    } // end for

    // ทำทางเลือก
    switch ( choise ) {
            case 1 :
                for ( int i = n , j = 0 ; i > 0 ; i--, j++ ) {
                    for ( int k = 0 ; k < n - j ; k++ ) {
                        leftmatrix[ i ] [ k ] = 0 ;
                    } // end for
                } // end for
                break ;
            case -1 :
                for ( int i = 0 ; i < n ; i++ ) {
                    for ( int k = n - 1 ; k  >  i ; k-- ) {
                        leftmatrix[ i ] [ k ] = 0 ;
                    } // end for
                } // end for
                break ;
            default :
                break ;
            } // end swith

    printf ( "Left Matrix =\n" ) ;
    for ( int i = 0 ; i < n ; i++ ) {
        for ( int k = 0 ; k < n ; k++ ) {
            printf ( "%d", leftmatrix[ i ] [ k ] ) ;
            if ( k + 1 < n ) {
                printf ( " " ) ;
            } // end if
        } // end for
        printf ( "\n" ) ;
    } // end for

    return 0 ;
} // main