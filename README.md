# Shopping-List
CSE232 Project4

Here is the project description.

For this project you'll be writing a program to help me get the best deals on my shopping list. I've gathered the inventories of a few local stores, so I can track what items they have in stock and how much they are selling things for. With that information (and knowing what I need to purchase), I can assemble a list of what I need to purchase from each location.
Here's the format for the stores' inventories:
4 Stores:
Local Grocery
East Lansing
Apples,10,$4.76
Sandwich,2,$1.99
Olive Bread,3,$2.99
Milk,7,$1.25
Eggs,40,$0.78
Candy,4,$0.51

Electronics R Here
Ann Arbor
Bargain Phone,2,$200.00
S Phone,4,$650.00
Fruit Phone,2,$700.00

Corner Store
East Lansing
Milk,30,$2.00
Eggs,2,$0.50
Candy,6,$1.00
Soda,5,$1.56
Bargain Phone,3,$185.00

Sparty's
East Lansing
Candy,10,$0.85
Soda,4,$1.50
Sandwich,3,$2.99
The first line of each store is the store's name, the next line is the store's location. The rest of the lines (before the blank line) is the inventory.
For each inventory line, there is the item's name, the quantity (the amount of that item the store has in stock), and the price. For example, the "Corner Store" has two eggs for sale and each egg costs fifty cents.
After reading in the store information, your program should output some summary information (to confirm it read in the data properly).
Here's what should be outputed:
Store Related Infomation (ordered by in-file order):
There are 4 store(s).
Local Grocery has 6 distinct items.
Electronics R Here has 3 distinct items.
Corner Store has 5 distinct items.
Sparty's has 3 distinct items.

Item Related Infomation (ordered alphabetically):
There are 10 distinct item(s) avaliable for purchase.
There are 10 Apples(s).
There are 5 Bargain Phone(s).
There are 20 Candy(s).
There are 42 Eggs(s).
There are 2 Fruit Phone(s).
There are 37 Milk(s).
There are 3 Olive Bread(s).
There are 4 S Phone(s).
There are 5 Sandwich(s).
There are 9 Soda(s).
Of course, with different stores and inventories, the output would be different.
After the store information is my shopping list. For each item, I want to get the best deal possible, even if that means going to different stores.
For example, if I want to buy 15 pieces of "Candy", I would need to go to the store with the cheapest Candy (the "Local Grocery") and buy everything they have (4 pieces), then go to the next cheapest place ("Sparty's") and buy them out as well (10 pieces). I still need one more piece of candy, so I need to go to "Corner Store". I need to determine how much all that candy costs (4 * $0.51 + 10 * $0.85 + 1 * $1.00 is $11.54)
Example Input Shopping List:
3 items on my shopping list:
15 Candy
100 Soda
1 S Phone
Example Output Shopping Instructions:
Shopping:
Trying to order 15 Candy(s).
3 store(s) sell Candy.
Total price: $11.54
Order 4 from Local Grocery in East Lansing
Order 10 from Sparty's in East Lansing
Order 1 from Corner Store in East Lansing

Trying to order 100 Soda(s).
2 store(s) sell Soda.
Total price: $13.80
Order 4 from Sparty's in East Lansing
Order 5 from Corner Store in East Lansing

Trying to order 1 S Phone(s).
1 store(s) sell S Phone.
Total price: $650.00
Order 1 from Electronics R Here in Ann Arbor

Be sure to bring $675.34 when you leave for the stores.
To faciliate testing, I've included a file named "input.txt" in your skeleton code that has the example input from this description (this file should be redirected into stdin). All the code for this project should be in a file named "main.cpp" in the folder named "project4".
Hints:
Be careful with rounding the numbers representing the prices, I need to know the costs to the exact penny. You might consider storing the prices in a long (as the number of cents). Example $4.50 is stored as (long) 450, so that there isn't any loss of precision from floating point values. 
You should be using the STL extensively to solve this project. For example: my solution has included 11 different STL headers.
