#pragma once
#include <string>
#include <fstream>
#include "Book.h" // For Date structure
#include "InventoryBook.h"
#include "CashierBook.h"
#include "BookList.h"


#define MAX_BOOKS 2048


/* REQ
 ISBN This is the International Standard Book Number. It is a unique number assigned to each book by the publisher.
 Title The title of the book.
 Author The book�s author.
 Publisher The company that publishes the book.
 Date Added The date the book was added to the inventory.
 Quantity-On-Hand The number of copies of the book in inventory.
 Wholesale Cost The price paid by Serendipity for each copy of the book.
 Retail Price The price Serendipity is charging for each copy of the book.
 */






class BookDB : public BookList
{
public:
	BookDB();
	BookDB(std::string filename, std::string salesFilename = "sales_data.txt");                // 2. Require the filename and parse the text file within the code
	~BookDB();
public:
	// Getters
	double   getWholesaleValue();
	double  getRetailValue();
	double	getNetProfit();
	double	getTax();

	// Mutators
	bool    readBooks();
	bool    writeBooks();
	void	writeOutput();
	
	bool	readSalesData(std::string filename);
	bool	writeSalesData(std::string filename);

	double  sellBook(unsigned long ISBN);						// These cannot be combined...
	double	sellBook(int idx);
	bool    removeBook(unsigned long ISBN, int quantity);		// <--probably just use this one

	void	addBook(const Book &bk);
	void	modifyBook(int idx, Book replacement);

	// Member Functions
	bool    sortBooks(SORT_METHOD sm);
	void	printByMethod(int verbosity, SORT_METHOD sm);

private:
	int     quantityItems;			// number of books including duplicate copies
	double  totalWholesaleValue;
	double  totalRetailValue;
	double  currentNetProfit;		// Total profit (retail - wholesale)
	double	currentSalesAmount;		// Basically how much $$$ should be in the register
	double	salesTax;

	std::string		salesFilename;
	std::fstream	salesFile;
	std::string		listFilename;
	std::fstream	listFile;
};
