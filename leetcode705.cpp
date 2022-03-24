  /*
  705. Design HashSet

  Design a HashSet without using any built-in hash table libraries.

  Implement MyHashSet class:

  void add(key) Inserts the value key into the HashSet.
  bool contains(key) Returns whether the value key exists in the HashSet or not.
  void remove(key) Removes the value key in the HashSet. If key does not exist in the HashSet, do nothing.

  Example 1:
    Input
      ["MyHashSet", "add", "add", "contains", "contains", "add", "contains", "remove", "contains"]
      [[], [1], [2], [1], [3], [2], [2], [2], [2]]
      Output
      [null, null, null, true, false, null, true, null, false]

  Explanation
    MyHashSet myHashSet = new MyHashSet();
    myHashSet.add(1);      // set = [1]
    myHashSet.add(2);      // set = [1, 2]
    myHashSet.contains(1); // return True
    myHashSet.contains(3); // return False, (not found)
    myHashSet.add(2);      // set = [1, 2]
    myHashSet.contains(2); // return True
    myHashSet.remove(2);   // set = [1]
    myHashSet.contains(2); // return False, (already removed)


  Constraints:
    0 <= key <= 106
    At most 104 calls will be made to add, remove, and contains.
*/

class MyHashSet {
public:
    vector<list<int>> map;
    int size;
    
    MyHashSet() {
        size = 100;
        map.resize(size);
    }
    
    int hash(int key) {
        return key%size;
    }
    
    list<int> :: iterator search(int key) {
        int i = hash(key);
        return find(map[i].begin(), map[i].end(), key);
    }
    
    void add(int key) {
        if(contains(key)) return;
        int i = hash(key);
        map[i].push_back(key);
    }
    
    void remove(int key) {
        if(!contains(key)) return;
        int i = hash(key);
        map[i].erase(search(key));
    }
    
    bool contains(int key) {
        int i = hash(key);
        if(search(key) != map[i].end()) return true;
        return false;
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */
