#lang racket
(define countitems
  (lambda (item lst)
    (cond
      ((null? lst) 0)
      ((equal? (car lst) item) (+ 1 (countitems item (cdr lst))))
      (else (+ 0 (countitems item (cdr lst))))
     )
   )
 )

(define member
  (lambda (lst)
    (cond
      ((null? lst) "error")
      ((equal? (length lst) 1) (car lst))
      (else (member (cdr lst)))
     )
   )
 )

(require math)
(define anyprimes?
  (lambda (lst)
    (cond
      ((null? lst) #f)
      ((prime? (car lst)) #t)
      (else (anyprimes? (cdr lst)))
     )
   )
 )

(define palindrome?
  (lambda (str)
    (let* ([str1 (string->list str)]
          [str2 (reverse (string->list str))])
      (if (equal? str1 str2) #t #f)
     )
   )
 )

(define removeDups
  (lambda (lst)
    (cond
      ((null? lst) '())
      ((member (car lst) (cdr lst)) (cons (car lst) (removeDups (cdr lst))))
      (else (removeDups (cdr lst)))
     )
   )
 )

(define sumsquares
  (lambda (lst)
    (foldl + 0 (map sqr lst))
   )
 )

(define miniList
  (lambda (lst)
    (foldl string>? "" lst)
   )
 )

(define removeit
  (lambda (item lst)
    (filter (lambda (v) (not (equal? v item))) lst)
   )
 )

(define countEmployment
  (lambda (lst status)
    (length (filter (lambda (x) (equal? (car(reverse x)) (list status))) lst))
   )
 )