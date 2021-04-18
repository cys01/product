
void readList(Product *p, int num);                     // read all of the products information
int updateList(Product *p, int num);                    // choice one of the index to update
int deleteList(Product *p, int num);                    // choice one of the index to delete

int loadList(char *file, Product *p);                   // load the data from the file, and save them on product array
void saveList(char *file, Product *p, int num);         // save all of the data in the file

void searchName(Product *p, int count);                 // find the certain name of products, and print its information
void searchPrice(Product *p, int count);                // find the certain price of products, and print its information
void searchStar(Product *p, int count);                 // find the products which have certain star_rating, and print its information

int menuSelect(); 					// select menu options
