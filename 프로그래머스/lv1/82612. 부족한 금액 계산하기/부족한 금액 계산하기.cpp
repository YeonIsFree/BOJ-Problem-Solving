using namespace std;

long long solution(int price, int money, int count)
{   
    long long sum = 0;
    for(int i = 1; i <= count; i++)
        sum += i * price;
    
    if(sum - money <= 0) return 0;
    else return sum - money;
    
}