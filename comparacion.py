import time

def f(x):
    return x*x*x - x - 2

def newton(x):
    for _ in range(20):
        x -= f(x) / (3*x*x - 1)
    return x

def brent(a, b):
    fa, fb = f(a), f(b)
    c, fc = a, fa
    d = e = b - a

    for _ in range(100):
        if abs(fc) < abs(fb):
            a, b, c = b, c, b
            fa, fb, fc = fb, fc, fb

        m = 0.5 * (c - b)

        if abs(m) < 1e-12 or fb == 0:
            return b

        if abs(e) > 1e-12 and abs(fa) > abs(fb):
            s = fb / fa

            if a == c:
                p = 2*m*s
                q = 1-s
            else:
                q1 = fa/fc
                q2 = fb/fc
                p = s*(2*m*q1*(q1-q2)-(b-a)*(q2-1))
                q = (q1-1)*(q2-1)*(s-1)

            if p > 0:
                q = -q
            else:
                p = -p

            if 2*p < min(3*m*q - abs(1e-12*q),
                          abs(e*q)):
                e = d
                d = p/q
            else:
                d = m
                e = m
        else:
            d = m
            e = m

        a = b
        fa = fb

        b += d if abs(d) > 1e-12 else (
            1e-12 if m > 0 else -1e-12
        )

        fb = f(b)

        if (fb > 0 and fc > 0) or (fb < 0 and fc < 0):
            c = a
            fc = fa
            e = d = b-a

    return b


N = 1000000

inicio = time.perf_counter()

resultado = 0
for _ in range(N):
    resultado += newton(1.5)

tiempo = time.perf_counter() - inicio

print("Newton Python:", resultado/N)
print("Tiempo Newton Python:", tiempo)


inicio = time.perf_counter()

resultado = 0
for _ in range(N):
    resultado += brent(1, 2)

tiempo = time.perf_counter() - inicio

print("Brent Python:", resultado/N)
print("Tiempo Brent Python:", tiempo)
