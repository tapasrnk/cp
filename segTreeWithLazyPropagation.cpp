struct segtree{
    //size of segtree array
    int size;
    //array storing the state of element with respect to operation
    vector<int>operation;
    //array storing the elements
    vector<int>values;
 
    //unique elements
    int NO_OPERATION = LLONG_MAX - 1;
    int NEUTRAL_ELEMENT = 0;
 
    int modify_op(int a,int b,int len){
        if(b==NO_OPERATION)return a;
        return b * len;
    }
 
    int calc_op(int a,int b){
        return a + b;
    }
 
    void apply_op(int &a,int b,int len){
        a=modify_op(a,b,len);
    }
 
    void init(int n){
        size = 1;
        while(size<n)size*=2;
        operation.assign(2*size,0LL);
        values.assign(2*size,0LL);
    }
 
    void propagate(int x,int lx,int rx){
        if(rx-lx==1){
            return;
        }
        int m=(lx+rx)/2;
        apply_op(operation[2*x+1],operation[x],1);
        apply_op(values[2*x+1],operation[x],m-lx);
        apply_op(operation[2*x+2],operation[x],1);
        apply_op(values[2*x+2],operation[x],rx-m);
        operation[x]=NO_OPERATION;
    }
 
    void modify(int l,int r,int v,int x,int lx,int rx){
        propagate(x,lx,rx);
        if(lx>=r || l>=rx)return ;
        if(lx>=l && rx<=r){
            apply_op(operation[x],v,1);
            apply_op(values[x],v,rx-lx);
            return ;
        }
        int m=(lx+rx)/2;
        modify(l,r,v,2*x+1,lx,m);
        modify(l,r,v,2*x+2,m,rx);
        values[x]=calc_op(values[2*x+1],values[2*x+2]);
    }
 
    void modify(int l,int r,int v){
        modify(l,r,v,0,0,size);
    }
 
    int calc(int l,int r,int x,int lx,int rx){
        propagate(x,lx,rx);
        if(lx>=r || l>=rx)return NEUTRAL_ELEMENT;
        if(lx>=l && rx<=r){
            return values[x];
        }
        int m=(lx+rx)/2;
        auto m1=calc(l,r,2*x+1,lx,m);
        auto m2=calc(l,r,2*x+2,m,rx);
        return calc_op(m1,m2);
    }
 
    int calc(int l,int r){
        return calc(l,r,0,0,size);
    }
};