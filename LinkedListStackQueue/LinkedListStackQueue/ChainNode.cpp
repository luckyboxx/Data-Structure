#include "ChainNode.h"
ChainNode::ChainNode(int element = 0, ChainNode *next = 0) { // ������
	data = element;
	link = next;
}
ChainNode::~ChainNode() {} // �ı���