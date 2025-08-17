// Definition for singly-linked list.
#[derive(PartialEq, Eq, Clone, Debug)]
pub struct ListNode {
    pub val: i32,
    pub next: Option<Box<ListNode>>,
}

impl ListNode {
    #[inline]
    fn new(val: i32) -> Self {
        ListNode { next: None, val }
    }
}

pub fn delete_duplicates(head: Option<Box<ListNode>>) -> Option<Box<ListNode>> {
    let mut dummy_head = ListNode::new(0);
    dummy_head.next = head;
    let mut prev = &mut dummy_head;
    loop {
        if prev.next.is_none() {
            return dummy_head.next.take();
        }
        if prev.next.as_ref().unwrap().next.is_none() {
            return dummy_head.next.take();
        }
        while prev.next.as_ref().unwrap().val
            != prev.next.as_ref().unwrap().next.as_ref().unwrap().val
        {
            prev = prev.next.as_mut().unwrap();
            if prev.next.as_ref().unwrap().next.is_none() {
                return dummy_head.next.take();
            }
        }
        let mut del_end = prev.next.as_mut().unwrap().next.as_mut().unwrap();
        while del_end.next.is_some() && del_end.val == del_end.next.as_ref().unwrap().val {
            del_end = del_end.next.as_mut().unwrap();
        }
        prev.next = del_end.next.take();
    }
}
