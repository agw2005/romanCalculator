#include <iostream>

float romanToEnglish(std::string roman) {
    int result = 0;
    for(int i = 0 ; i < size(roman) ; i++)
        //0 , 1 , 2 , 3 , 4 , ...
    {
        int temp = 0;

        if(roman[i] == 'I')
        {
            if(roman[i+1] == 'V' || roman[i+1] == 'X')
            {temp += 1;temp *= -1;}
            else
            {temp += 1;}

            result += temp;
        }

        else if(roman[i] == 'V')
        {result += 5;}

        else if(roman[i] == 'X')
        {
            if(roman[i+1] == 'L' || roman[i+1] == 'C')
            {temp += 10;temp *= -1;}
            else
            {temp += 10;}

            result += temp;
        }

        else if(roman[i] == 'L')
        {result += 50;}

        else if(roman[i] == 'C')
        {
            if(roman[i+1] == 'D' || roman[i+1] == 'M')
            {temp += 100;temp *= -1;}
            else
            {temp += 100;}

            result += temp;
        }

        else if(roman[i] == 'D')
        {result += 500;}

        else //roman[i] == 'M' (1000)
        {result += 1000;}
    }
    return (float)result;
}

void calculator(float a=0.0, char b='+', float c=0.0){
    float hasil;
    if(b == '+'){hasil = a+c;std::cout<<a<<" "<<b<<" "<<c<<" = "<<hasil;}
    else if(b == '-'){hasil = a-c;std::cout<<a<<" "<<b<<" "<<c<<" = "<<hasil;}
    else if(b == '*'){hasil = a*c;std::cout<<a<<" "<<b<<" "<<c<<" = "<<hasil;}
    else if(b == '/'){
        if(c == 0){std::cout<<a<<" "<<b<<" "<<c<<" = "<<"Tidak terdefinisi";}
        else{hasil = a/c;std::cout<<a<<" "<<b<<" "<<c<<" = "<<hasil;}
    }
    else if(b == '^'){
        if(c == 0){hasil = 1;std::cout<<a<<" "<<b<<" "<<c<<" = "<<hasil;}
        if(c > 0){
            hasil = 1;
            for(int i = 1;i<=(int)c;i++){
                hasil *= a;
            }
            std::cout<<a<<" "<<b<<" "<<c<<" = "<<hasil;
        }
        else{
            c = c*(-1);
            hasil = 1;
            for(int i = 1;i<=(int)c;i++){
                hasil *= a;
            }
            if(hasil == 0){std::cout<<a<<" "<<b<<" -"<<c<<" = "<<"Tidak terdefinisi";}
            else {std::cout<<a<<" "<<b<<" -"<<c<<" = 1/"<<hasil<<" atau "<<1/hasil;}
        }
    }
    else if(b == '%'){
        if(c == 0){std::cout<<a<<" "<<b<<" "<<c<<" = 0";}
        else if(c > 0){
            if(a < 0){
                hasil = a*-1;
                for(int i = (int)a*-1 ; i>=(int)c ; i-=(int)c){
                    hasil -= c;
                }
                std::cout<<a<<" "<<b<<" "<<c<<" = "<<hasil*-1;
            }
            else if(a > 0){
                hasil = a;
                for(int i = (int)a ; i>=(int)c ; i-=(int)c){
                    hasil -= c;
                }
                std::cout<<a<<" "<<b<<" "<<c<<" = "<<hasil;
            }
        }
        else{
            c *= -1;
            if(a < 0){
                hasil = a*-1;
                for(int i = (int)a*-1 ; i>=(int)c ; i-=(int)c){
                    hasil -= c;
                }
                std::cout<<a<<" "<<b<<" -"<<c<<" = "<<hasil*-1;
            }
            else if(a > 0){
                hasil = a;
                for(int i = (int)a ; i>=(int)c ; i-=(int)c){
                    hasil -= c;
                }
                std::cout<<a<<" "<<b<<" -"<<c<<" = "<<hasil;
            }
        }
    }
    else{std::cout<<"Error, operator tidak dikenal";}
}

int main()
{
    std::string angkaPertama, angkaKedua;
    char tipeOperator;

    std::cout<<"Masukan angka pertama!\n";
    std::cin>>angkaPertama;

    std::cout<<"Masukan simbol operasi yang akan dilakukan!\n";
    std::cin>>tipeOperator;

    std::cout<<"Masukan angka kedua!\n";
    std::cin>>angkaKedua;

    calculator(
            romanToEnglish(angkaPertama),
            tipeOperator,
            romanToEnglish(angkaKedua)
            );
}