
#include "avl.h"


int height(pavl N){
    if (N == NULL)
        return 0;
    return N->height;
}

int max(int a, int b){
    return (a > b)? a : b;
}

pavl newNode(Station st){
    pavl temp = (pavl) malloc(sizeof(pavl)*6);
    temp->st = st;
    temp->left = NULL;
    temp->right = NULL;
    temp->height = 1;
    return temp;
}

pavl rightRotate(pavl y){
    pavl x = y->left;
    pavl T2 = x->right;

    x->right = y;
    y->left = T2;

    y->height = max(height(y->left), height(y->right)) + 1;
    x->height = max(height(x->left),height(x->right)) + 1;

    return x;
}

// A utility function to left rotate subtree rooted with x

pavl leftRotate(pavl x){
    pavl y = x->right;
    pavl T2 = y->left;

    y->left = x;
    x->right = T2;

    x->height = max(height(x->left), height(x->right)) + 1;
    y->height = max(height(y->left), height(y->right)) + 1;

    return y;
}

// Get Balance factor of node N
int getBalance(pavl N){
    if (N == NULL)
        return 0;
    return height(N->left) - height(N->right);
}

// Recursive function to insert a key in the subtree rooted
// with node and returns the new root of the subtree.
pavl insertt1AVL(pavl a, Station st){
    if (a == NULL)
        return(newNode(st));
    else if (a->st.codes == st.codes){
        if(a->st.min > st.min && st.min != 0.000000) a->st.min = st.min;
        if(a->st.max < st.max && st.max != 0.000000) a->st.max = st.max;

        if(a->st.min > st.avg ) a->st.min = st.avg;
        if(a->st.max < st.avg ) a->st.max = st.avg;

        a->st.avg = (a->st.avg + st.avg ) /2 -0.5;

    } else if (st.codes < a->st.codes)
        a->left = insertt1AVL(a->left, st);
    else if (st.codes > a->st.codes)
        a->right = insertt1AVL(a->right, st);
    else
        return a;

    a->height = 1 + max(height(a->left), height(a->right));

    int balance = getBalance(a);

    if (balance > 1 && st.codes < a->left->st.codes)
        return rightRotate(a);

    if (balance < -1 && st.codes > a->right->st.codes)
        return leftRotate(a);

    if (balance > 1 && st.codes > a->left->st.codes)
    {
        a->left = leftRotate(a->left);
        return rightRotate(a);
    }

    if (balance < -1 && st.codes < a->right->st.codes)
    {
        a->right = rightRotate(a->right);
        return leftRotate(a);
    }

    return a;
}

pavl insertp1AVL(pavl a, Station st){
    if (a == NULL)
        return(newNode(st));
    else if (a->st.codes == st.codes){
        if (a->st.min > st.avg && st.avg != 0.000000) a->st.min = st.avg;
        if (a->st.max < st.avg && st.avg != 0.000000) a->st.max = st.avg;

        a->st.avg = (a->st.avg + st.avg ) /2 -0.5;

    } else if (st.codes < a->st.codes)
        a->left = insertp1AVL(a->left, st);
    else if (st.codes > a->st.codes)
        a->right = insertp1AVL(a->right, st);
    else
        return a;

    a->height = 1 + max(height(a->left), height(a->right));

    int balance = getBalance(a);

    if (balance > 1 && st.codes < a->left->st.codes)
        return rightRotate(a);

    if (balance < -1 && st.codes > a->right->st.codes)
        return leftRotate(a);

    if (balance > 1 && st.codes > a->left->st.codes)
    {
        a->left = leftRotate(a->left);
        return rightRotate(a);
    }

    if (balance < -1 && st.codes < a->right->st.codes)
    {
        a->right = rightRotate(a->right);
        return leftRotate(a);
    }

    return a;
}

void infixeAVL(pavl a, FILE* fp){
    if (a != NULL){
        infixeAVL(a->left,fp);
        fprintf(fp, "%d, %f, %f, %f\n", a->st.codes, a->st.avg, a->st.min, a->st.max);
        infixeAVL(a->right,fp);
    }

}
