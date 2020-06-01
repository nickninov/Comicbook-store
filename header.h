// Get the number of elements in an array
#define num(arr) (sizeof(arr) / sizeof (*arr))

// Get the size of a struct item
#define itemSize sizeof(struct item)

// Length for the char name array
#define NAME 80

// Length for the char description array
#define DESC 250

// The initial number of items that need to be allocated in memory
#define INITIAL_CAPACITY 1

/* 
    Structure of a single item:
    float price;
    int quantity;
    char name[80];
    char description[250]; 
*/
struct item {
    float price;
    int quantity;
    char name[NAME];
    char description[DESC];    
};