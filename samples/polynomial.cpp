#include <stdio.h>
#include <stdlib.h>

struct node {
    int coeff;
    int expon;
    struct node *link, *prev;
};
typedef struct node *NODE;

NODE getnode() {
    NODE x;
    x = (NODE)malloc(sizeof(struct node));
    return x;
}

void display(NODE head);

NODE attach(int coeff, int expon, NODE head) {
    NODE temp, cur;
    temp = getnode();
    temp->coeff = coeff;
    temp->expon = expon;
    cur = head->link;
    while (cur->link != head) {
        cur = cur->link;
    }
    cur->link = temp;
    temp->link = head;
    return head;
}

NODE read_poly(NODE head) {
    int i = 1, coeff, expon;
    printf("\nEnter the coefficient as 0 to end the polynomial ");
    while (1) {
        printf("\nEnter the %d term:", i++);
        printf("\ncoeffecient = ");
        scanf("%d", &coeff);
        if (coeff == 0)
            break;
        printf("power of x of the entered coeffecient = ");
        scanf("%d", &expon);
        head = attach(coeff, expon, head);
    }
    return head;
}

NODE poly_mult(NODE head1, NODE head2, NODE head3) {
    NODE cur1, cur2;
    if (head1->link == head1 || head2->link == head2) {
        printf("\nMultiplied polynomial is zero polynomial");
        return 0;
    }
    cur1 = head1->link;
    while (cur1 != head1) {
        cur2 = head2->link;
        while (cur2 != head2) {
            head3 = attach(cur1->coeff * cur2->coeff, cur1->expon + cur2->expon, head3);
            cur2 = cur2->link;
        }
        cur1 = cur1->link;
    }
    return head3;
}

NODE poly_add(NODE head1, NODE head2, NODE head4) {
    NODE cur3, cur4;
    cur3 = head1->link;
    int exists = 0;
    while (cur3 != head1) {
        exists = 0;
        cur4 = head2->link;
        while (cur4 != head2) {
            int coeffe = cur3->coeff;
            if (cur3->expon == cur4->expon) {
                exists = 1;
                head4 = attach(cur3->coeff + cur4->coeff, cur3->expon, head4);
            }
            cur4 = cur4->link;
        }
        if (exists == 0)
            head4 = attach(cur3->coeff, cur3->expon, head4);
        cur3 = cur3->link;
    }
    return head4;
}

void display(NODE head) {
    NODE temp;
    if (head->link == head) {
        printf("\nPolynomial does not exist");
        return;
    }
    temp = head->link;
    while (temp != head) {
        printf("%dx^%d", temp->coeff, temp->expon);
        temp = temp->link;
        if (temp != head)
            printf(" + ");
    }
}

int main() {
    NODE head1, head2, head3, head4;
    head1 = getnode();
    head2 = getnode();
    head3 = getnode();
    head4 = getnode();

    head1->link = head1;
    head2->link = head2;
    head3->link = head3;
    head4->link = head4;

    printf("\ninput polynomial 1 :\n");
    head1 = read_poly(head1);
    printf("\ninput polynomial 2 :\n");
    head2 = read_poly(head2);
    head3 = poly_mult(head1, head2, head3);
    head4 = poly_add(head1, head2, head4);

    printf("\nPolynomial 1:");
    display(head1);
    printf("\nPolynomial 2:");
    display(head2);
    printf("\nmultiplication Result:  ");
    display(head3);
    printf("\naddition Result:  ");
    display(head4);
    printf("\n");
}
