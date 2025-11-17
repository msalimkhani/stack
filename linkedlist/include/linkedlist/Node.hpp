#pragma once

#ifndef __NODE_HPP__
#define __NODE_HPP__

namespace DataStructures
{
  template <typename T>

  class Node
  {
  public:
    T data;
    Node<T> *next;
  };
} // namespace DataStructures

#endif