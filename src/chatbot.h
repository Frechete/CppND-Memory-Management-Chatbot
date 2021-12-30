#ifndef CHATBOT_H_
#define CHATBOT_H_

#include <wx/bitmap.h>

#include <iostream>
#include <memory>
#include <string>
#include <utility>

class GraphNode;  // forward declaration
class ChatLogic;  // forward declaration

class ChatBot {
 private:
  // data handles (owned)
  //  wxBitmap *_image;  // avatar image
  std::unique_ptr<wxBitmap> _image;

  // data handles (not owned)
  GraphNode *_currentNode;
  GraphNode *_rootNode;
  ChatLogic *_chatLogic;

  // proprietary functions
  int ComputeLevenshteinDistance(std::string s1, std::string s2);

 public:
  // constructors / destructors
  ChatBot();  // constructor WITHOUT memory allocation
  explicit ChatBot(
      const std::string &filename);  // constructor WITH memory allocation
  ~ChatBot();

  //// STUDENT CODE
  ////
  ChatBot(const ChatBot &other) = delete;  // copy constructor
  ChatBot(ChatBot &&other) noexcept;       // move constructor
  // ChatBot &operator=(ChatBot other) = delete;  // move/copy assignment
  // ChatBot &operator=(ChatBot &&other) noexcept;  // move/copy assignment

  ChatBot &operator=(ChatBot &&other) {
    if (this == &other) {
      return *this;
    }
    _chatLogic = other._chatLogic;
    _rootNode = other._rootNode;
    _currentNode = other._currentNode;
    _image = std::move(other._image);
    // std::cout << this << ": move constructor" << std::endl;
    other._chatLogic = nullptr;
    other._rootNode = nullptr;
    other._currentNode = nullptr;
    std::cout << this << ": move/copy assignment" << std::endl;
    return *this;
  };
  ////
  //// EOF STUDENT CODE

  // getters / setters
  void SetCurrentNode(GraphNode *node);
  void SetRootNode(GraphNode *rootNode) { _rootNode = rootNode; }
  void SetChatLogicHandle(ChatLogic *chatLogic) { _chatLogic = chatLogic; }
  ChatLogic *GetChatLogicHandle() { return _chatLogic; }
  wxBitmap *GetImageHandle() { return _image.get(); }

  // communication
  void ReceiveMessageFromUser(std::string message);
};

#endif /* CHATBOT_H_ */
