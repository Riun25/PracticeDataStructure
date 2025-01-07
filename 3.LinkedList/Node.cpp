#include "Node.h"

Node::Node()
{
}

Node::Node(int _data)
	:mData(_data)
{
}

std::ostream& operator<<(std::ostream& _os, const Node& _node)
{
	_os << "Data: " << _node.mData;
	return _os;
}
