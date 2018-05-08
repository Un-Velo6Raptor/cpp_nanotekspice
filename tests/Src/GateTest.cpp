/*
** EPITECH PROJECT, 2018
** cpp_nanotekspice
** File description:
** Created by anais.breant@epitech.eu,
*/

#include <criterion/criterion.h>
#include "AndGate.hpp"
#include "NandGate.hpp"
#include "NorGate.hpp"
#include "NotGate.hpp"
#include "OrGate.hpp"
#include "XorGate.hpp"
#include "IComponent.hpp"

Test(GateTest, AndGate_FalseValue) {
	nts::IComponent *first;
	nts::IComponent *second;
	nts::AndGate test("AndGate_FalseValue", first, second);

	cr_assert_eq(test.truthTableExec(nts::FALSE, nts::FALSE), nts::FALSE);
}

Test(GateTest, AndGate_TrueValue) {
	nts::IComponent *first;
	nts::IComponent *second;
	nts::AndGate test("AndGate_TrueValue", first, second);

	cr_assert_eq(test.truthTableExec(nts::TRUE, nts::TRUE), nts::TRUE);
}

Test(GateTest, AndGate_UndefinedFalseValue) {
	nts::IComponent *first;
	nts::IComponent *second;
	nts::AndGate test("AndGate_UndefineFalseValue", first, second);

cr_assert_eq(test.truthTableExec(nts::UNDEFINED, nts::FALSE), nts::FALSE);
}

Test(GateTest, AndGate_UndefinedValue) {
	nts::IComponent *first;
	nts::IComponent *second;
	nts::AndGate test("AndGate_UndefineValue", first, second);

cr_assert_eq(test.truthTableExec(nts::UNDEFINED, nts::TRUE), nts::UNDEFINED);
}

Test(GateTest, NandGate_TrueValue) {
	nts::IComponent *first;
	nts::IComponent *second;
	nts::NandGate test("NandGate_FalseValue", first, second);

cr_assert_eq(test.truthTableExec(nts::TRUE, nts::TRUE), nts::FALSE);
}

Test(GateTest, NandGate_FalseValue) {
	nts::IComponent *first;
	nts::IComponent *second;
	nts::NandGate test("NandGate_TrueValue", first, second);

cr_assert_eq(test.truthTableExec(nts::FALSE, nts::FALSE), nts::TRUE);
}

Test(GateTest, NandGate_UndefinedValue) {
nts::IComponent *first;
nts::IComponent *second;
nts::NandGate test("NandGate_UndefinedValue", first, second);

cr_assert_eq(test.truthTableExec(nts::FALSE, nts::UNDEFINED), nts::UNDEFINED);
}

Test(GateTest, NandGate_UndefinedFalseValue) {
nts::IComponent *first;
nts::IComponent *second;
nts::NandGate test("NandGate_UndefinedFalseValue", first, second);

cr_assert_eq(test.truthTableExec(nts::TRUE, nts::UNDEFINED), nts::FALSE);
}

Test(GateTest, NorGate_FalseValue) {
nts::IComponent *first;
nts::IComponent *second;
nts::NorGate test("NorGate_TrueValue", first, second);

cr_assert_eq(test.truthTableExec(nts::FALSE, nts::FALSE), nts::TRUE);
}

Test(GateTest, NorGate_TrueValue) {
nts::IComponent *first;
nts::IComponent *second;
nts::NorGate test("NorGate_TrueValue", first, second);

cr_assert_eq(test.truthTableExec(nts::TRUE, nts::TRUE), nts::FALSE);
}

Test(GateTest, NorGate_UndefinedFalseValue) {
nts::IComponent *first;
nts::IComponent *second;
nts::NorGate test("NorGate_UndefinedFalseValue", first, second);

cr_assert_eq(test.truthTableExec(nts::UNDEFINED, nts::TRUE), nts::FALSE);
}

Test(GateTest, NorGate_UndefinedValue) {
nts::IComponent *first;
nts::IComponent *second;
nts::NorGate test("NorGate_UndefinedValue", first, second);

cr_assert_eq(test.truthTableExec(nts::UNDEFINED, nts::FALSE), nts::UNDEFINED);
}

Test(GateTest, NotGate_TrueValue) {
nts::IComponent *first;
nts::NotGate test("NotGate_TrueValue", first);

cr_assert_eq(test.truthTableExec(nts::TRUE), nts::FALSE);
}

Test(GateTest, NotGate_FalseValue) {
nts::IComponent *first;
nts::NotGate test("NotGate_TrueValue", first);

cr_assert_eq(test.truthTableExec(nts::FALSE), nts::TRUE);
}

Test(GateTest, OrGate_TrueValue) {
nts::IComponent *first;
nts::IComponent *second;
nts::OrGate test("OrGate_TrueValue", first, second);

cr_assert_eq(test.truthTableExec(nts::TRUE, nts::TRUE), nts::TRUE);
}

Test(GateTest, OrGate_FalseValue) {
nts::IComponent *first;
nts::IComponent *second;
nts::OrGate test("OrGate_FalseValue", first, second);

cr_assert_eq(test.truthTableExec(nts::TRUE, nts::TRUE), nts::TRUE);
}

Test(GateTest, OrGate_UndefinedValue) {
nts::IComponent *first;
nts::IComponent *second;
nts::OrGate test("OrGate_UndefinedValue", first, second);

cr_assert_eq(test.truthTableExec(nts::UNDEFINED, nts::FALSE), nts::UNDEFINED);
}

Test(GateTest, OrGate_UndefinedTrueValue) {
nts::IComponent *first;
nts::IComponent *second;
nts::OrGate test("OrGate_UndefinedTrueValue", first, second);

cr_assert_eq(test.truthTableExec(nts::UNDEFINED, nts::TRUE), nts::TRUE);
}

Test(GateTest, XorGate_TrueValue) {
nts::IComponent *first;
nts::IComponent *second;
nts::XorGate test("XorGate_TrueValue", first, second);

cr_assert_eq(test.truthTableExec(nts::TRUE, nts::TRUE), nts::FALSE);
}

Test(GateTest, XorGate_FalseValue) {
nts::IComponent *first;
nts::IComponent *second;
nts::XorGate test("XorGate_FalseValue", first, second);

cr_assert_eq(test.truthTableExec(nts::TRUE, nts::TRUE), nts::FALSE);
}

Test(GateTest, XorGate_UndefinedValue) {
nts::IComponent *first;
nts::IComponent *second;
nts::XorGate test("XorGate_UndefinedValue", first, second);

cr_assert_eq(test.truthTableExec(nts::UNDEFINED, nts::FALSE), nts::UNDEFINED);
}

Test(GateTest, XorGate_UndefinedTrueValue) {
nts::IComponent *first;
nts::IComponent *second;
nts::XorGate test("XorGate_UndefinedValue", first, second);

cr_assert_eq(test.truthTableExec(nts::UNDEFINED, nts::TRUE), nts::UNDEFINED);
}