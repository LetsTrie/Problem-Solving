// Segment tree (+Lazy propagation)
// Problem 1: https://codeforces.com/edu/course/2/lesson/4/1/practice/contest/273169/problem/A

class SegmentTree {
  vector<LL> tree;
  vector<LL> lazy;

public:
	SegmentTree() {}
	SegmentTree(vector<int>& vec, int _length) {
	   tree.resize(_length << 2, 0);
	   lazy.resize(_length << 2, 0);
	   build(vec, 1, 0, _length - 1);
	}
 
	void build(vector<int>& vec, int pos, int left, int right) {
	  if(left == right) {
	  	tree[pos] = vec[left], lazy[pos] = 0; 
	  	return ;
	  }
	  int mid = (left + right) / 2, l = pos << 1, r = l | 1;
	  build(vec, l, left , mid), build(vec, r, mid + 1 , right);
	  tree[pos] = tree[l] + tree[r], lazy[pos] = lazy[l] + lazy[r];
	}

	void update(int pos, int left, int right, int tl, int tr, int value) {
	  int mid = (left + right) / 2, l = pos << 1, r = l | 1;
	  if(lazy[pos]) {
	    tree[pos] = (LL)lazy[pos] * (right - left + 1);
	    if(left != right) lazy[l] = lazy[pos] , lazy[r] = lazy[pos];
	    lazy[pos] = 0; 
	  } 
	  if(left > right or left > tr or right < tl) return;
	  if(tl <= left and tr >= right) {
	    tree[pos] = (LL)value * (right - left + 1);
	    if(left != right) lazy[l] = value , lazy[r] = value; 
	    return;
	  } 
	  update(l, left, mid, tl, tr, value), update(r, mid + 1, right, tl, tr, value);
	  tree[pos] = tree[l] + tree[r];
	}

	LL get(int pos, int left, int right, int tl, int tr) {
	  int mid = (left + right) / 2, l = pos << 1, r = l | 1;
	  if(lazy[pos]) {
	    tree[pos] = (LL)lazy[pos] * (right - left + 1);
	    if(left != right) lazy[l] = lazy[pos], lazy[r] = lazy[pos];
	    lazy[pos] = 0; 
	  } 
	  if(left > right or left > tr or right < tl) return 0LL;
	  if(tl <= left and tr >= right) return tree[pos];
	  return get(l, left, mid, tl, tr) + get(r, mid + 1, right, tl, tr);
	}
};

// SegmentTree* segmentTree = new SegmentTree(vec, N);
// segmentTree -> build(vec, 1, 0, N - 1);
// segmentTree -> update(1, 0, N - 1, tl, tl, tr);
// segmentTree -> get(1, 0, N - 1, tl, tr - 1);
