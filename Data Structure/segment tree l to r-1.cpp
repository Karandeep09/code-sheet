struct segtree
{ int size;
  vector<ll> sums; 
  void init(int n)
  {   size = 1;
      while(size<n) size*=2;
      sums.assign(2 * size, 0LL);
  } 
  void pull(int x)
  {
      sums[x] = sums[2*x+1] + sums[2*x+2];
  }
  void build(vector<int> &a, int x, int lx, int rx)
  {
      if(rx-lx==1)
      {
          if(lx<(int)a.size())
          {
              sums[x]=a[lx]; 
          }
         return; 
      } 
      int m = (lx+rx)/2;
      build(a,2*x+1,lx,m);
      build(a,2*x+2,m,rx); 
      pull(x);
  }
  void build(vector<int> &a)
  {
      build(a,0,0,size);
  } 
  void update(int idx, int val, int x, int lx, int rx)
  { 
     if(rx-lx==1)
     {
         sums[x] = val;
         return;
     }     
     int m = (lx+rx)/2;
     if(idx<m)
     update(idx,val,2*x+1,lx,m);
     else 
     update(idx,val,2*x+2,m,rx);
     pull(x);
  }
  void update(int idx,int val)
  {
      update(idx,val,0,0,size);
  } 
  ll query(int l,int r, int x, int lx, int rx)
  {  
      if(r<=lx || l>=rx) return 0;
      if( l<=lx && rx<=r ) return sums[x];
      int m = (lx+rx)/2;
      ll a = query(l,r,2*x+1,lx,m);
      ll b = query(l,r,2*x+2,m,rx);
      return a+b;
  }
  ll query(int l,int r)
  {
      return query(l,r,0,0,size);
  }
};