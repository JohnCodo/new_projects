//

//type for node list
typedef struct elem{
    float info;
    struct elem *urm;
}node;


//show all list
void displayNode(node *p);

node *addNode(node *base, float newInfo);

node *deleteNode(node *base, float info);

void meniuInterfation();
