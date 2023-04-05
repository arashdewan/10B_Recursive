//
//  main.cpp
//  HW7_updated
//
//  Created by Arash Dewan on 2/26/23.
//

#include <iostream>
#include <chrono>

using namespace std;

long double xpower(long double x, int n)
{
    if (n<=0)
        return 1;
    else
        return x*xpower(x,n-1);
}

long double xpower_helper(long double x, int n, int result)
{
    if (n<=0)
        return result;
    else
        return xpower_helper(x, n-1, result * x);
}
long double xpower_h(long double x, int n)
{
    return xpower_helper(x,n,1);
}


int main()
{
    cout<<xpower(2,4)<<endl;
    cout<<xpower(3,3)<<endl;
    cout<<xpower_h(2,4)<<endl;
    cout<<xpower_h(3,3)<<endl;

    auto t0 = std::chrono::high_resolution_clock::now();
    xpower(1.01,2000);
    auto te = std::chrono::high_resolution_clock::now();
    std::cout << "Without the helper function " << std::chrono::duration_cast<std::chrono::nanoseconds>(te - t0).count() << " ns\n";
    t0 = std::chrono::high_resolution_clock::now();
    xpower_h(1.01,2000);
    te = std::chrono::high_resolution_clock::now();
    std::cout << "With the helper function " << std::chrono::duration_cast<std::chrono::nanoseconds>(te - t0).count() << " ns\n";
    
    cout << "Arash Dewan 2/26/2023" << endl;
    
    return 0;
}
