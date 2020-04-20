#include <iostream>
#include "pqueue.h"
int random(int min, int max){
    static bool first = true;
    if (first){
        srand(time(NULL));
        first = false;
    }
    return min+rand() %(max-min);
}

std::string randStr(size_t length){
    char str[length];
    size_t i = 0;
    int r;
    for (i=0;i<length;i++){
        for(;;){
            r = rand()%57 + 65;
            if((r>=65 && r <= 90) || (r>=97 && r<=122)){
                str[i] = (char) r;
                break;
            }
        }
    }
    return std::string(str);
}
void initRand();
std::string generateRandomString(unsigned len);

int main() {
    initRand();
    priorityqueue pq;
    std::string str1;
    float wert;

    for (int i = 0;i<10;i++)
    {
        float randomFloat = static_cast <float> (rand()) / (static_cast <float> (RAND_MAX/20));
        str1 = generateRandomString(4);
        pq.insert(str1,randomFloat);

    }
    std::cout << "Array representation:" << std::endl;
    std::cout << std::endl;
    std::cout << std::endl;

    pq.toScreen();
    for (int k = 0;k <4;k++)
    {
        try{
            std::cout << "Extracting min val:" << std::endl;

            std::cout << pq.extractMin() << std::endl;
            std::cout << "Array representation:" << std::endl;

            pq.toScreen();
        }catch (QueueException e){
            std::cout << e.OutStr() << std::endl;
        }
    }
    std::cout << "Finished extracting and deleting 4 elements" << std::endl;
    std::cout << std::endl;
    std::cout << std::endl;

    std::cout << "Array representation:" << std::endl;

    pq.toScreen();





    std::cout << std::endl;
    std::cout << std::endl;

    std::cout << "Adding Element: xkcf, Prio: 1.0" << std::endl;
    std::cout << "Adding Element: xkdf, Prio: 1.5" << std::endl;
    std::cout << "Adding Element: xkef, Prio: 2.0" << std::endl;
    pq.insert("xkcf",1.0);
    pq.insert("xkdf",1.5);
    pq.insert("xkef",2.0);

    std::cout << "Array representation:" << std::endl;

    pq.toScreen();
    std::cout << std::endl;
    std::cout << std::endl;

    std::cout << "Getting minimum w/o deleting" << std::endl;
    std::cout << pq.minimum() << std::endl;

    std::cout << "Array representation:" << std::endl;

    pq.toScreen();
    std::cout << std::endl;
    std::cout << std::endl;

    std::cout << "Decreasing Key of xkef to 0.1 " << std::endl;
    pq.decreaseKey("xkef",0.1);

    std::cout << "Array representation:" << std::endl;

    pq.toScreen();
    std::cout << std::endl;
    std::cout << std::endl;

    std::cout << "Removing entry xkdf " << std::endl;
    pq.remove("xkdf");

    std::cout << "Array representation:" << std::endl;

    pq.toScreen();
    std::cout << std::endl;
    std::cout << std::endl;

    std::cout << "Removing entry xkef " << std::endl;
    pq.remove("xkef");

    std::cout << "Array representation:" << std::endl;

    pq.toScreen();
    std::cout << std::endl;
    std::cout << std::endl;

    std::cout << "Removing entry xkcf " << std::endl;
    pq.remove("xkdf");

    std::cout << "Array representation:" << std::endl;

    pq.toScreen();
    std::cout << std::endl;
    std::cout << std::endl;

    int kk;
    for ( int k = 0;k <9;k++)
    {
        try{
            std::cout << "Extracting min val:" << std::endl;

            std::cout << pq.extractMin() << std::endl;
            std::cout << "Array representation:" << std::endl;

            pq.toScreen();
        }catch (QueueException e){
            std::cout << e.OutStr() << std::endl;
        }
        kk =k;
    }
    std::cout << "Finished extracting and deleting "<< kk << "elements" << std::endl;
    std::cout << std::endl;
    std::cout << std::endl;






    return 0;
}

void initRand()
{
    srand((unsigned) time(0));
}

std::string generateRandomString(unsigned len)
{
    std::string str;
    char alphanum[] = {'a','b','c','d','e','f','g','h','i','j','k','l','m','n'};

    for (unsigned i = 0;i < len;i++)
    {
        str+=  alphanum[ rand() % sizeof(alphanum-1)];

    }
    return str;
}