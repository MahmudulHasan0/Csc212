 
#include <cstdlib> //size_t

class moneyBag{
private:
    size_t oneDollar_Count, fiveDollar_Count, tenDollar_Count, twentyDollar_Count;
public:
    moneyBag();
    //WHAT THE CUSTOMER GIVES AND YOU PUT INTO YOUR BAG
    void putInOne(size_t q){oneDollar_Count = oneDollar_Count + q;}
    void putInFive(size_t q){fiveDollar_Count = fiveDollar_Count + q;}
    void putInTen(size_t q){tenDollar_Count = tenDollar_Count + q;}
    void putInTwenty(size_t q){twentyDollar_Count = twentyDollar_Count + q;}
    //WHAT YOU RETURN BACK TO CUSTOMER FROM YOUR BAG
    void takeOutOne(size_t q){oneDollar_Count = oneDollar_Count - q;} 
    void takeOutFive(size_t q){fiveDollar_Count = fiveDollar_Count - q;}
    void takeOutTen(size_t q){tenDollar_Count = tenDollar_Count - q;}
    void takeOutTwenty(size_t q){twentyDollar_Count = twentyDollar_Count - q;}
    //TOAL IN HIS POCKET:
    int total(){ return (oneDollar_Count + 5*fiveDollar_Count + 10*tenDollar_Count + 20*twentyDollar_Count); }
    void printEach();
    void putInBag(int clientMoney);
    void takeOutBag(int clientMoney);
};

