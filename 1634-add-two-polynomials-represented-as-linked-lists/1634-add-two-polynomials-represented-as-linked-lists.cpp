/**
 * Definition for polynomial singly-linked list.
 * struct PolyNode {
 *     int coefficient, power;
 *     PolyNode *next;
 *     PolyNode(): coefficient(0), power(0), next(nullptr) {};
 *     PolyNode(int x, int y): coefficient(x), power(y), next(nullptr) {};
 *     PolyNode(int x, int y, PolyNode* next): coefficient(x), power(y), next(next) {};
 * };
 */

class Solution {
public:
    PolyNode* addPoly(PolyNode* poly1, PolyNode* poly2) {
        PolyNode* dummy_head = new PolyNode();
        PolyNode* head = dummy_head;
        
        while (poly1 && poly2) {
            if (poly1->power > poly2->power) {
                head->next = poly1;
                head = head->next;
                poly1 = poly1->next;
            }
            else if (poly1->power < poly2->power) {
                head->next = poly2;
                head = head->next;
                poly2 = poly2->next;
            }
            else {
                int coff = poly1->coefficient + poly2->coefficient;
                if (coff != 0) {
                    head->next = new PolyNode(coff, poly1->power);
                    head = head->next;
                }
                poly1 = poly1->next;
                poly2 = poly2->next;
            }
        }
        head->next = poly1 ? poly1 : poly2;
        return dummy_head->next;
    }
};