typedef long long LL;
 
// SegTree* segmentTree = new SegTree();
class SegTree {
public:
    LL sum, max_value, lazy;
    SegTree *left_node, *right_node;
    
    SegTree(){
        sum = 0;
        lazy = 0;
        max_value = INT_MIN;
        left_node = nullptr;
        right_node = nullptr;
    }
    
    // segmentTree -> build(vec, 0, n - 1); 
    void build(vector<int>& vec, int left, int right) {
      if(left == right) {
          this -> sum       =   vec[left];
          this -> max_value =   vec[left];
          this -> lazy      =   0; 
          return;
      }
      
      left_node = new SegTree();
      right_node = new SegTree();
      
      int mid = (left + right) / 2;
      build(vec, left , mid);
      build(vec, mid + 1 , right);
      
      left_node -> build(vec, left , mid);
      right_node -> build(vec, mid + 1 , right);
      
      this -> sum       =   (left_node -> sum) + (right_node -> sum); 
      this -> max_value =   max(left_node -> max_value, right_node -> max_value); 
      this -> lazy      =   0; 
    }

    // segmentTree-> update(0, n - 1, tl, tr, v);
    void update(int left, int right, int tl, int tr, int value) {
      int mid = (left + right) / 2;

      if(this -> lazy) {
        this -> max_value   += this -> lazy;
        this -> sum         += (LL) this -> lazy * (right - left + 1);
        if(left != right) {
            left_node   -> lazy +=  this -> lazy;
            right_node  -> lazy +=  this -> lazy;
        }
        this -> lazy = 0; 
      } 
      
      if(left > right or left > tr or right < tl) return;
      
      
      if(tl <= left and tr >= right) {
        this -> max_value   += value;
        this -> sum         += (LL)value * (right - left + 1);
        if(left != right) {
            left_node   -> lazy +=  value;
            right_node  -> lazy +=  value;
        }
        return;
      } 
      
      left_node 	-> update(left, mid, tl, tr, value);
      right_node 	-> update(mid + 1, right, tl, tr, value);
      
      this -> sum       =   (left_node -> sum) + (right_node -> sum); 
      this -> max_value =   max(left_node -> max_value, right_node -> max_value); 
    }

    // segmentTree-> get(0, n - 1, 0, n - 1)
    LL get(int left, int right, int tl, int tr) {
      int mid = (left + right) / 2;

      if(this -> lazy) {
        this -> max_value   += this -> lazy;
        this -> sum         += (LL) this -> lazy * (right - left + 1);
        if(left != right) {
            left_node   -> lazy +=  this -> lazy;
            right_node  -> lazy +=  this -> lazy;
        }
        this -> lazy = 0; 
      } 
      
      if(left > right or left > tr or right < tl) return 0LL;
      if(tl <= left and tr >= right) return this -> max_value;

      int left_result = left_node -> get(left, mid, tl, tr);
      int right_result = right_node -> get(mid + 1, right, tl, tr);
      
      return max(left_result, right_result);
    }
};