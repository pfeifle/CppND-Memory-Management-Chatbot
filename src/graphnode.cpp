#include "graphedge.h"
#include "graphnode.h"

GraphNode::GraphNode(int id)
{
    _id = id;
}

GraphNode::~GraphNode()
{
    //// STUDENT CODE
    ////

    //delete _chatBot; // _chatBot is not created by Graphnode but by chatlogic
    // and should therefore also not be deleted here.

    ////
    //// EOF STUDENT CODE
}

void GraphNode::AddToken(std::string token)
{
    _answers.push_back(token);
}

void GraphNode::AddEdgeToParentNode(GraphEdge *edge)
{
    _parentEdges.push_back(edge);
}

//void GraphNode::AddEdgeToChildNode(GraphEdge *edge)
void GraphNode::AddEdgeToChildNode(std::unique_ptr<GraphEdge> edge)
{
    //_childEdges.push_back(edge);
    _childEdges.push_back(std::move(edge));
}

//// STUDENT CODE
////
//void GraphNode::MoveChatbotHere(ChatBot *chatbot)
void GraphNode::MoveChatbotHere(ChatBot  chatbot)
{
//    _chatBot = chatbot; 
    _chatBot.reset(new ChatBot());
    *_chatBot = std::move(chatbot);
    _chatBot->SetCurrentNode(this);
}

void GraphNode::MoveChatbotToNewNode(GraphNode *newNode)
{
  /*
    newNode->MoveChatbotHere(_chatBot);
    _chatBot = nullptr; // invalidate pointer at source
*/
  newNode->MoveChatbotHere (std::move(*_chatBot));
  _chatBot.reset();
}
////
//// EOF STUDENT CODE

GraphEdge *GraphNode::GetChildEdgeAtIndex(int index)
{
    //// STUDENT CODE
    ////

    //return _childEdges[index];
    return (_childEdges[index]).get();

    ////
    //// EOF STUDENT CODE
}