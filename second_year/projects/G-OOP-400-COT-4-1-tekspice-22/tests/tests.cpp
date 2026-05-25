/*
** EPITECH PROJECT, 2026
** snd_year_projects
** File description:
** tests
*/

#include "../include/Circuit.hpp"
#include <criterion/criterion.h>
#include <criterion/redirect.h>
using namespace nts;

void input_output(size_t pin)
{
    try {
    InputComponent _in;
    OutputComponent _out;

    _out.setLink(1, _in, 1);
    cout << _out.compute(pin) << endl;
    } catch (CircuitError& e) {
        cerr << e.what() << endl;
    }
}

Test (test_1, valid) {
    cr_redirect_stdout();
    cr_redirect_stderr();

    input_output(1);
    cr_assert_stdout_eq_str("U\n");
    cr_assert_stderr_eq_str("");
}

Test (test_2, non_valid) {
    cr_redirect_stdout();
    cr_redirect_stderr();

    input_output(2);
    cr_assert_stdout_eq_str("");
    cr_assert_stderr_eq_str("Retrieve Error: Invalid pin ID\n");
}

Test (test_3, only_output) {
    cr_redirect_stdout();
    cr_redirect_stderr();

    OutputComponent _out;

    cout << _out.compute(1) << endl;
    cr_assert_stdout_eq_str("U\n");
}

Test (test_4, only_input) {
    cr_redirect_stdout();
    cr_redirect_stderr();

    InputComponent _in;

    cout << _in.compute(1) << endl;
    cr_assert_stdout_eq_str("U\n");
}

Test (test_5, clock_component_no_update) {
    cr_redirect_stderr();
    cr_redirect_stdout();

    ClockComponent _cl;

    _cl = Tristate::True;
    cout << _cl.compute(1) << endl;
    cr_assert_stdout_eq_str("U\n");
}

Test (test_5, clock_component_update_one) {
    cr_redirect_stderr();
    cr_redirect_stdout();

    ClockComponent _cl;

    _cl = Tristate::True;
    _cl.simulate(1);
    cout << _cl.compute(1) << endl;
    cr_assert_stdout_eq_str("1\n");
}

Test (test_6, clock_component_update_two) {
    cr_redirect_stderr();
    cr_redirect_stdout();

    ClockComponent _cl;

    _cl = Tristate::True;
    _cl.simulate(1);
    _cl.simulate(2);
    cout << _cl.compute(1) << endl;
    cr_assert_stdout_eq_str("0\n");
}

Test (test_7, true_component) {
    cr_redirect_stdout();
    cr_redirect_stderr();

    TrueComponent _true;
    cout << _true.compute(1) << endl;
    cr_assert_stdout_eq_str("1\n");
}

Test (test_8, false_component) {
    cr_redirect_stdout();
    cr_redirect_stderr();

    FalseComponent _false;
    cout << _false.compute(1) << endl;
    cr_assert_stdout_eq_str("0\n");
}

Test (test_9, invalid_pins_false) {
    cr_redirect_stderr();
    cr_redirect_stdout();

    FalseComponent _false;

    try {
        cout << _false.compute(2) << endl;
    } catch (CircuitError& e) {
        cerr << e.what() << endl;
    }
    
    cr_assert_stdout_eq_str("");
    cr_assert_stderr_eq_str("Retrieve Error: Invalid pin ID\n");
}

Test (test_10, and_component) {
    cr_redirect_stderr();
    cr_redirect_stdout();

    TrueComponent _true;
    FalseComponent _false;
    AndComponent _and;

    _and.setLink(1, _false, 1);
    _and.setLink(2, _true, 1);

    cout << _and.compute(3) << endl;
    cr_assert_stdout_eq_str("0\n");
}

Test (test_11, and_componend_uninitialized_input) {
    cr_redirect_stdout();
    cr_redirect_stderr();

    InputComponent _in;
    AndComponent _and;

    _in = Tristate::False;
    _and.setLink(1, _in, 1);

    cout << _and.compute(3) << endl;
    cr_assert_stdout_eq_str("U\n");
}

Test (test_12, and_componend_initialized_input) {
    cr_redirect_stdout();
    cr_redirect_stderr();

    InputComponent _in;
    TrueComponent _true;
    AndComponent _and;

    _in = Tristate::True;
    _in.simulate(1);
    _and.setLink(1, _in, 1);
    _and.setLink(2, _true, 1);

    cout << _and.compute(3) << endl;
    cr_assert_stdout_eq_str("1\n");
}

Test (test_13, or_component) {
    cr_redirect_stderr();
    cr_redirect_stdout();

    TrueComponent _true;
    FalseComponent _false;
    OrComponent _or;

    _or.setLink(1, _false, 1);
    _or.setLink(2, _true, 1);

    cout << _or.compute(3) << endl;
    cr_assert_stdout_eq_str("1\n");
}

Test (test_14, or_componend_uninitialized_input) {
    cr_redirect_stdout();
    cr_redirect_stderr();

    InputComponent _in;
    OrComponent _or;

    _in = Tristate::False;
    _or.setLink(1, _in, 1);

    cout << _or.compute(3) << endl;
    cr_assert_stdout_eq_str("U\n");
}

Test (test_15, or_componend_initialized_input) {
    cr_redirect_stdout();
    cr_redirect_stderr();

    InputComponent _in;
    FalseComponent _false;
    OrComponent _or;

    _in = Tristate::False;
    _in.simulate(1);
    _or.setLink(2, _false, 1);
    _or.setLink(1, _in, 1);

    cout << _or.compute(3) << endl;
    cr_assert_stdout_eq_str("0\n");
}

Test (test_16, xor_component) {
    cr_redirect_stderr();
    cr_redirect_stdout();

    TrueComponent _true;
    FalseComponent _false;
    XorComponent _xor;

    _xor.setLink(1, _false, 1);
    _xor.setLink(2, _true, 1);

    cout << _xor.compute(3) << endl;
    cr_assert_stdout_eq_str("1\n");
}

Test (test_17, xor_componend_uninitialized_input) {
    cr_redirect_stdout();
    cr_redirect_stderr();

    InputComponent _in;
    XorComponent _xor;

    _in = Tristate::False;
    _xor.setLink(1, _in, 1);

    cout << _xor.compute(3) << endl;
    cr_assert_stdout_eq_str("U\n");
}

Test (test_18, xor_componend_initialized_input) {
    cr_redirect_stdout();
    cr_redirect_stderr();

    InputComponent _in;
    FalseComponent _false;
    XorComponent _xor;

    _in = Tristate::False;
    _in.simulate(1);
    _xor.setLink(2, _false, 1);
    _xor.setLink(1, _in, 1);

    cout << _xor.compute(3) << endl;
    cr_assert_stdout_eq_str("0\n");
}

Test (test_19, not_component) {
    cr_redirect_stderr();
    cr_redirect_stdout();

    FalseComponent _false;
    NotComponent _not;

    _not.setLink(1, _false, 1);

    cout << _not.compute(2) << endl;
    cr_assert_stdout_eq_str("1\n");
}

Test (test_20, not_componend_uninitialized_input) {
    cr_redirect_stdout();
    cr_redirect_stderr();

    InputComponent _in;
    NotComponent _not;

    _in = Tristate::False;
    _not.setLink(1, _in, 1);

    cout << _not.compute(2) << endl;
    cr_assert_stdout_eq_str("U\n");
}

Test (test_21, not_componend_initialized_input) {
    cr_redirect_stdout();
    cr_redirect_stderr();

    InputComponent _in;
    NotComponent _not;

    _in = Tristate::True;
    _in.simulate(1);
    _not.setLink(1, _in, 1);

    cout << _not.compute(2) << endl;
    cr_assert_stdout_eq_str("0\n");
}

Test (test_22, and_not) {
    cr_redirect_stdout();
    cr_redirect_stderr();

    InputComponent _in;
    AndComponent _and;
    NotComponent _not;

    _and.setLink(1, _in, 1);
    _not.setLink(1, _and, 3);
    _in = Tristate::False;
    _in.simulate(1);
    cout << _not.compute(2) << endl;
    cr_assert_stdout_eq_str("1\n");
}
