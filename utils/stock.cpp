#include <iostream>
#include <string>
#include "../heads/stock.h"

void Stock::acquire(const std::string & co, long n, double pr){
    company = co;
    if (n < 0){
        std::cout << "Number of shares can't be negative; "
                  << company << " shares set to 0.\n";
        shares = 0;
    } else {
        shares = n;
    }
    share_val = pr;
    set_tot();
}

void Stock::buy(long num, double price){
    shares += num;
    share_val = price;
    set_tot();
}

void Stock::sell(long num, double price){
    shares = (shares-num>=0)?shares-num:0;
    share_val = price;
    set_tot();
}

void Stock::update(double price){
    share_val = price;
    set_tot();
}

void Stock::show(){
    std::cout << "Company: " << company
              << "  shares: " << shares << "\n"
              << "  Share Price: $" << share_val
              << "  Total Worth: $" << total_val << std::endl; 
}
