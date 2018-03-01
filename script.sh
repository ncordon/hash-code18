#!/bin/bash

(./self-driving < ./a_example.in) > ./a_example.out
(./self-driving < ./b_should_be_easy.in) > ./b_should_be_easy.out
(./self-driving < ./c_no_hurry.in) > ./c_no_hurry.out
(./self-driving < ./d_metropolis.in) > ./d_metropolis.out
(./self-driving < ./e_high_bonus.in) > ./e_high_bonus.out
