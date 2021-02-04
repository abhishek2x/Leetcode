class MyHashSet
{
public:
  // vector<bool> v(100000, false);
  // bool v[1000000] = false;
  bool v[1000005]{false};

  MyHashSet()
  {
  }

  void add(int key)
  {
    v[key] = true;
  }

  void remove(int key)
  {
    v[key] = false;
  }

  /** Returns true if this set contains the specified element */
  bool contains(int key)
  {
    return v[key];
  }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */