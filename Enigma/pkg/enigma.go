package pkg

import (
	"math/rand"
	"time"
)

const (
	alphabet = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ"
)

type Reflect struct {
	reflect map[byte]byte
}

type Rotor struct {
	rotorA []byte
	rotorB []byte
	index  int
}

type Enigma struct {
	reflect Reflect
	rotorA  Rotor
	rotorB  Rotor
	rotorC  Rotor
}

func initEnigma(indexA, indeB int) Enigma {
	return Enigma{
		reflect: initReflect(),
		rotorA:  initRotor(indexA),
		rotorB:  initRotor(indexB),
		rotorC:  initRotor(0),
	}
}

func shuffledBytes() []byte {
	rand.Seed(time.Now().UnixNano())

	shuffledBytes := []byte(alphabet)

	for i := len(alphabet) - 1; i > 0; i-- {
		j := rand.Intn(i + 1)
		shuffledBytes[i], shuffledBytes[j] = shuffledBytes[j], shuffledBytes[i]
	}

	return shuffledBytes
}

func initRotor(index int) Rotor {
	return Rotor{
		rotorA: shuffledBytes(),
		rotorB: shuffledBytes(),
		index: index,
	}
}

func initReflect(index int) Reflect {
	a := shuffledBytes()
	b := shuffledBytes()

	reflect := map[byte]byte{}

	for i := 0; i < len(a); i++ {
		reflect[a[i]] = b[i] 
	}

	return Reflect{
		reflect: reflect,
	}
}
