@from：Excel内置的文档

# SQRT function

## Description

Returns a positive square root.

## Syntax

SQRT(number)

The SQRT function syntax has the following arguments:

- **Number**  Required. The number for which you want the square root. // +实数

# POWER function

## Description

Returns the result of a number raised to a power.

## Syntax

POWER(number, power)

The POWER function syntax has the following arguments:

- **Number**  Required. The base number. It can be any real number. // ±实数
- **Power**  Required. The exponent to which the base number is raised. // ±实数

## Remark

The "^" ==operator== can be used instead of POWER to indicate to what power the base number is to be raised, such as in 5^2. // 对数据的要求和POWER function一样

# EXP function

## Description

Returns e raised to the power of number. The constant e equals 2.71828182845904, the base of the natural logarithm.

## Syntax

EXP(number)

The EXP function syntax has the following arguments:

- **Number**  Required. The exponent applied to the base e. // ±实数

## Remarks

- To calculate powers of other bases, use the ==exponentiation operator== (^).
- EXP is the inverse of LN, the natural logarithm of number.

# 总结

- exponentiation operator (^)可以说是万金油了，可以完美替代SQRT function、POWER function
- 以上函数和exponentiation operator (^)都是接受实数数据的，至于数据的能否为正/负、能否为0，要看具体的算式了