#pragma once

#include <vector>
#include <string>
#include <iostream>
using namespace std;

struct TreeNode {
  TreeNode(const string& s) : str(s), height(10) {}
  void AddChild(TreeNode* c) { children_.push_back(c); }

  string str;
  vector<TreeNode*> children_;
  int height;
};

void TreeTravel(TreeNode* root, int indent, int& height) {
  for (int i = 0; i < indent; i++)
    cout << " ";
  cout << root->str << endl;
  height += root->height;

  vector<TreeNode*>::iterator it = root->children_.begin();
  while (it != root->children_.end()) {
    if(height >= 50)
      break;
    TreeTravel(*it, indent + 2, height);
    ++it;
  }
}

void DoTreeTravel()
{
  TreeNode* A = new TreeNode("A");
  TreeNode* A1 = new TreeNode("A1");
  TreeNode* A2 = new TreeNode("A2");
  TreeNode* A3= new TreeNode("A3");
  A->AddChild(A1);
  A->AddChild(A2);
  A->AddChild(A3);

  TreeNode* A21 = new TreeNode("A23");
  TreeNode* A22 = new TreeNode("A22");
  TreeNode* A23 = new TreeNode("A23");
  A2->AddChild(A21);
  A2->AddChild(A22);
  A2->AddChild(A23);


  TreeNode* B = new TreeNode("B");
  TreeNode* B1 = new TreeNode("B1");
  B->AddChild(B1);

  TreeNode* C = new TreeNode("C");
  TreeNode* C1 = new TreeNode("C1");
  TreeNode* C2 = new TreeNode("C2");
  C->AddChild(C1);
  C->AddChild(C2);

  TreeNode* root = new TreeNode("Root");
  root->AddChild(A);
  root->AddChild(B);
  root->AddChild(C);

  int height = 0;
  TreeTravel(root, 0, height);

}