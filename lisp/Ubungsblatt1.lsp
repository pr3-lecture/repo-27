;1a
(defun rotiere (liste)
    (append (cdr liste) (list (car liste)))
)
(print (rotiere '(eins zwei drei vier)))

;1b
(defun neues-vorletztes (element liste)
    (setq neueliste (reverse liste)) 
    (reverse (append (list(car neueliste)) (list element) (cdr neueliste)))
)
(print (neues-vorletztes 'dreieinhalb '(eins zwei drei vier)))

;1c
(defun my-length (liste)
    (cond
        ((null liste) 0) ; Abbruchbedinung (leere Liste)
        (t (+ 1 (my-length (cdr liste)))) ; "Zähler" erhöhen und funktion rekursiv aufrufen mit verkürtzer liste
    )
)
(print (my-length '(eins zwei drei vier)))

;1d
(defun my-lengthR (liste)
    (cond
        ((null liste) 0) ; Abbruchbedinung (leere Liste)
        (t (cond
           ((listp (car liste)) ; ist das erste Element eine geschachtelte Liste
            (+ 0
               (my-lengthR (car liste)) ; Berechnung geschachtelter Liste
               (my-lengthR (cdr liste)) ; Berechnung der restlichen (der geschachtelten Liste übergeordneten) Liste
            )
            )
            (t (+ 1(my-lengthR (cdr liste)))); erstes Element ist atomar --> Berechne restliche Liste + 1
           )
        )
     )
)
(print(my-lengthR '(eins zwei (zwei (zwei drei) eins) drei vier)))

;1e
(defun my-reverse (liste)
    (cond
        ((null liste) nil); Abbruchbedinung (leere Liste)
        (T (append (my-reverse (cdr liste)) (list (car liste)))); füge erstes Element als Liste an Reversion der restlichen Liste an 
    )
)
(print(my-reverse '(eins zwei (zwei (zwei drei) eins) drei vier)))

;1f
(defun my-reverseR (liste)
    (cond
        ((null liste) nil); Abbruchbedinung (leere Liste)
        (t (cond
               ((listp (car liste)); ist das erste Element eine geschachtelte Liste
                (append 
                 (my-reverseR (cdr liste)) ; Reversion der restlichen (der geschachtelten Liste übergeordneten) Liste
                 (list(my-reverseR (car liste))) ; Reversion geschachtelter Liste
                )
               )
               (T (append (my-reverseR (cdr liste)) (list (car liste))))
            )
         )
     )
); erstes Element ist atomar --> Reversion restliche Liste+ hänge Atom an
(print(my-reverseR '(eins zwei (zwei (zwei drei) eins) drei vier)))

;2a
;Ein Baumknoten wird durch eine Liste mit 3 Elementen abgebildet   (Schlüssel Kindesknoten Kindesknoten) => Baumknoten
;Das erste Element ist ein atomar und stellt den Schlüssel dar
;die anderen beiden Elemente sind wiederum Listen mit gleicher Beschreibung und stellen die Kindesknoten dar
;Blätter haben die Form  ...(Schlüssel () ())...
;Beispiel:
;                    8
;                 3     10
;               1   6     14
;                  4 7   13    
;
;(8 (3 (1 () ()) (6 (4 () ()) (7 () ())))(10 () (14 (13 () ()) ())))

(setq baum '(8 (3 (1 () ()) (6 (4 () ()) (7 () ())))(10 () (14 (13 () ()) ()))))

;2b
;inorder
(defun inorder (tree)
    (let 
     (
      (left (car (cdr tree)))
      (right (car (cdr (cdr tree))))
     )
     (cond
         ((not (null left)) (inorder left));Traverse the left subtree by recursively calling the in-order function
     )
     (print (car tree));Display the data part of the root
     (cond
         ((not (null right)) (inorder right));Traverse the right subtree by recursively calling the in-order function
     )
    )
)
(print 'Inorder)
(inorder baum)

;postorder
(defun postorder (tree)
    (let 
     (
      (left (car (cdr tree)))
      (right (car (cdr (cdr tree))))
     )
     (cond
         ((not (null left)) (postorder left));Traverse the left subtree by recursively calling the post-order function
     )
     (cond
         ((not (null right)) (postorder right));Traverse the right subtree by recursively calling the post-order function
     )
     (print (car tree));Display the data part of the root
    )
)
(print 'Postorder)
(postorder baum)

;preorder
(defun preorder (tree)
    (let
     (
      (left (car (cdr tree)))
      (right (car (cdr (cdr tree))))
     )
     (print (car tree));Display the data part of the root
     (cond
         ((not (null left)) (preorder left));Traverse the left subtree by recursively calling the pre-order function
     )
     (cond
         ((not (null right)) (preorder right));Traverse the right subtree by recursively calling the pre-order function
     )
    )
)
(print 'Preorder)
(preorder baum)