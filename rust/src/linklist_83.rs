// Definition for singly-linked list.
#[derive(PartialEq, Eq, Clone, Debug)]
pub struct ListNode {
    pub val: i32,
    pub next: Option<Box<ListNode>>,
}

pub fn delete_duplicates(mut head: Option<Box<ListNode>>) -> Option<Box<ListNode>> {
    if head.is_none() {
        return head;
    }
    let mut prev = head.as_mut().unwrap();
    while let Some(cur) = prev.next.as_mut() {
        if cur.val == prev.val {
            prev.next = cur.next.take();
        } else {
            // prev = cur;
            prev = prev.next.as_mut().unwrap();
        }
    }
    head
}

/* This solution is not pretty.
pub fn delete_duplicates(mut head: Option<Box<ListNode>>) -> Option<Box<ListNode>> {
    if head.is_none() {
        return head;
    }
    let mut prev = head.as_mut().unwrap();
    while let Some(cur) = prev.next.as_mut() {
        if cur.val == prev.val {
            prev.next = cur.next.take();
        } else {
            if let Some(next) = prev.next.as_mut() {
                prev = next;
            } else {
                break;
            }
        }
    }
    return head;
}
*/

/* This solution is slower.
pub fn delete_duplicates(mut head: Option<Box<ListNode>>) -> Option<Box<ListNode>> {
    if head.is_none() {
        return head;
    }
    let mut prev = head.as_mut().unwrap();
    while let Some(mut cur) = prev.next.take() {
        if cur.val != prev.val {
            prev.next = Some(cur);
            prev = prev.next.as_mut().unwrap();
        } else {
            prev.next = cur.next.take();
        }
    }
    head
}
*/
