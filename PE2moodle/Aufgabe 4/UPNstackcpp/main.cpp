//
// Created by Nico 

//

#include <iostream>

#include <iomanip>
#include <cstring>
#include <vector>
#include "Stack.h"
using namespace std;

int main() {
    Stack Sta(1);
    string input;
    float right, left, t;
    char *ptr;
    cout << "Bitte arithmetischen Ausdruck(post-fix) eingeben" << endl;
   // std::string string("1 2 3 4 12 4 1244  ");
    getline(cin, input);
    vector<char> buffer(input.size() + 1);
    strcpy(&buffer[0], input.c_str());
    ptr = strtok(&buffer[0], " ");

    while (ptr != nullptr) {

        if (strcmp(ptr, "+" )==0){
            t=Sta.computeAdditive();
            Sta.push(t);
        }
        else if (strcmp(ptr,"-")==0){
            t=Sta.computeSubstractive();
            Sta.push(t);
        }
        else if (strcmp(ptr,"*")==0){
            t=Sta.computeMultiplicative();
            Sta.push(t);
        }
        else if (strcmp(ptr,"/")==0){
            try{
            t=Sta.computeDivision();
            Sta.push(t);}
            catch (const int i){
                cout << i << endl;
            }

        }
        else

        Sta.push(stof(ptr,NULL));

        ptr=strtok(NULL," ");
        //std::cout << ptr << std::endl;

    }
    Sta.toScreen();
}
/*
    cout << "Bitte arithmetischen Ausdruck(post-fix) eingeben" << endl;
    getline(cin, input);
    unsigned long k=0,start=0;
    for (unsigned long i =start;i<=input.length();i++){
        k +=1;
        if(isspace(input[i])){
            temp = input.substr(start,k-1);
            k=0;
            start = i+1;
            if (temp == "+"){
                left= Sta.top();
                Sta.pop();
                right= Sta.top();
                Sta.pop();
                t=left + right;
                Sta.push(t);
            }
            else
                Sta.push(stof(temp));




        }
        else if (i == input.length()){
            temp = input.substr(start,(k-1));
            if (temp == "+"){
                left= Sta.top();
                Sta.pop();
                right= Sta.top();
                Sta.pop();
                t=left + right;
                Sta.push(t);
            }else
                Sta.push(stof(temp));

            //break;

        }

        //temp = input[i];
        //Sta.push(stof(temp));

       cout << temp << endl;
    }
    Sta.toScreen();


    }*/






   /* Stack Sta(1);
    string input;
    string temp;

    cout << "Bitte arithmetischen Ausdruck(post-fix) eingeben" << endl;
    getline(cin, input);
    unsigned long k=0,start=input.length();
    for (unsigned long i =input.length()-1;i>=0;i--){
        k +=1;
        if(isspace(input[i])){
            temp = input.substr(i+1,k-1);
            k=0;
            start = i-1;
           // Sta.push(stof(temp));


           // zahl ausschneiden aus string;grenze = leerzeichen;cut und strcpy+\0
        }
        else if (i == 0){
            temp = input.substr(i+(k-1),k-1);
            //Sta.push(stof(temp));

        }
        //temp = input[i];
        //Sta.push(stof(temp));

        cout << temp << endl;
    }
    Sta.toScreen();
    // Operatoren nicht in den Stack schreiben, zusätzliches char *array mit eingelesenen operatoren
    */


    /*
    Stack Sta(1);
    string input ;
    int sze=0;
    //char defaultStr= '';

    //cout << input <<endl;
    while(input != "Ende"){
        cout << "Bitte Zahl eingeben" << endl;
        cin >> input ;

        if (cin.fail()){
            cout << "\ncin fail ERRNO12\n";
            input= 12;
        }
        else if ( input == "Ende")
            break;
        else if (input == "Dec")
        {
            Sta.pop();
            break;
        }
        else if (input == "give")
        {cout << Sta.top()<< endl;}

        else if (input == "+") {
            input.clear();
            float temp;
            while (sze > 1) {
                temp = Sta.top();
                Sta.pop();
                sze -= 1;
                temp = temp + Sta.top();

                Sta.pop();

                Sta.push(temp);


            }
            Sta.pop();
            sze -= 1;
            {
                stringstream stream;
                stream << fixed << setprecision(2) << temp;
                input = stream.str();
            }


           //cout << input << endl;


        }
        if (input == "*"){
            input.clear();
            float temp;
            while (sze > 1){
                temp = Sta.top();
                Sta.pop();
                sze -= 1;
                temp = temp * Sta.top();
                Sta.pop();
                Sta.push(temp);
            }
            Sta.pop();
            sze -=1;
            {
                stringstream stream;
                stream << fixed << setprecision(2) << temp;
                input = stream.str();
            }
        }
       if (input == "-"){
           input.clear();
           float temp;
           while (sze > 1 ){
               temp = Sta.top();
               Sta.pop();
               sze -= 1;
               temp = Sta.top()-temp  ;
               Sta.pop();
               Sta.push(temp);
           }
           Sta.pop();
           sze -=1;
           {
               stringstream stream;
               stream << fixed << setprecision(2) << temp;

               input = stream.str();
           }
       }

        //cout << input << endl;

        Sta.push(stof(input));
        sze += 1;
        //stringstream().swap(defaultStr);
        //cin.clear();


        //cout << input << endl;


    }
    Sta.toScreen();
    Sta.~Stack();
     */




