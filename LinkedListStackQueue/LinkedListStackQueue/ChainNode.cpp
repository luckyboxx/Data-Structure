#include "ChainNode.h"
ChainNode::ChainNode(int element = 0, ChainNode *next = 0) { // 생성자
	data = element;
	link = next;
}
ChainNode::~ChainNode() {} // 파괴자