#include "GroceryPurchase.hpp"
#include "gtest/gtest.h"


TEST(Groceries, SetnCheckTaxRate)
{
    GroceryPurchase g{0.03};
    ASSERT_EQ(0.03, g.getTaxRate());
}



TEST(Groceries, CheckIUntaxabletems)
{
    GroceryPurchase g{0.03};
    g.addItem({"MILK",10,20,false});
    ASSERT_EQ(200,g.getTotal());
    g.addItem({"CHICKEN",20,200,false});
    ASSERT_EQ(4200,g.getTotal());
    ASSERT_EQ(4200,g.getSubtotal());
    ASSERT_EQ(0,g.getTax());
}

TEST(Groceries, CheckTaxableItems)
{
    GroceryPurchase g{0.03};
    g.addItem({"XBOX",2,400,true});
    ASSERT_EQ(824,g.getTotal());
    g.addItem({"4K TV",1,1900,true});
    ASSERT_EQ(2781,g.getTotal());
    ASSERT_EQ(2700,g.getSubtotal());
    ASSERT_EQ(81,g.getTax());
}

TEST(Groceries, Clear)
{
    GroceryPurchase g{0.03};
    g.addItem({"XBOX",2,400,true});
    ASSERT_EQ(824,g.getTotal());
    g.clear();
    ASSERT_EQ(0,g.getTotal());
    ASSERT_EQ(0,g.getSubtotal());
}
