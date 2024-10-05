using System.Linq.Expressions;
using System.Runtime.InteropServices;

public class LinkedList
{
  public static void SayHello() => Console.WriteLine("LL says Hello");

  #region Design Singly Linked List
  public static void Design(){
    var ll = new MyLinkedList();
    ll.AddAtHead(7);
    ll.AddAtHead(2);
    ll.AddAtHead(1);
    ll.AddAtIndex(3, 0);
    Console.WriteLine("Length " + ll.GetLength());
    Console.WriteLine(ll.Get(2));
    ll.DeleteAtIndex(2);
    Console.WriteLine("Length " + ll.GetLength());
    Console.WriteLine(ll.Get(2));
    Console.WriteLine(ll.Get(3));
    ll.AddAtHead(6);
    Console.WriteLine(ll.Get(0));
    Console.WriteLine(ll.Get(3));
    Console.WriteLine(ll.Get(4));

  }
  #endregion
}

internal class Node{
  public int Data{ get; set; }
  public Node? Next { get; set; }
  public Node(int val){
    Data = val;
    Next = null;
  }
  public Node(int val, Node? node){
    Data = val;
    Next = node;
  }
}

internal class MyLinkedList
{
  private Node? Head { get; set; } = null;
  private Node? Tail { get; set; } = null;
  private int Length { get; set; } = 0;

  public int Get(int index){
    if(Length == 0 || index >= Length || index < 0){
      return -1;
    }
    if(Head == null || Tail == null){
      return -1;
    }
    if(index == 0){
      return Head.Data;
    }
    if(index == Length-1){
      return Tail.Data;
    }
    var current = Head;
    for(int i = 0; i < index; i++){
      current = current?.Next;
    }
    return current?.Data == null ? -1 : current.Data;
  }

  public int GetLength(){
    return Length;
  }

  public void AddAtHead(int data){
    var node = new Node(data);
    if(Length == 0){
      Head = node;
      Tail = Head;
    }
    else{
      node.Next = Head;
      Head = node;
    }
    Length++;
    return;
  }

  public void AddAtTail(int data){
    var node = new Node(data);
    if(Length == 0){
      Tail = node;
      Head = Tail;
    }
    else if(Tail != null){
      Tail.Next = node;
      Tail = node;
    }
    Length++;
    return;
  }

  public void AddAtIndex(int index, int data){
    if(index == 0){
      AddAtHead(data);
      return;
    }
    else if(index > Length || index < 0){
      return;
    }
    else if(index == Length){
      AddAtTail(data);
      return;
    }
    else {
      var current = Head;
      for(int i = 1; i < index; i++){
        current = current?.Next;
      }
      var node = new Node(data, current?.Next);
      if (current != null) current.Next = node;
    }
    Length++;
    return;
  }

  public void DeleteAtIndex(int index){
    if(index >= Length || index < 0){
      return;
    }
    else if(index == 0){
      Head = Head?.Next;
      if(Length == 1){
        Tail = null;
      }
      Length--;
      return;
    }
    else{
      var current = Head;
      for(int i = 1; i < index; i++){
        current = current?.Next;
      }
      if(current!= null && current.Next == Tail){
        Tail = null;
        current.Next = null;
        Tail = current;
      }
      else{
        if(current != null) 
          current.Next = current.Next?.Next;
      }
      Length--;
      return;
    }
  }
}