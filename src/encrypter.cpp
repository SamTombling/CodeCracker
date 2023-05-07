#include "encrypter.h"

Encrypter::Encrypter(const QString &plainText)
{
    m_plainText = plainText;
}

QString Encrypter::cypherText() const
{
    return m_cypherText;
}

void Encrypter::setShifts(int newShifts)
{
    m_shifts = newShifts;
}

void Encrypter::substitution()
{
    for (QChar letter : m_plainText)
    {
        if (letter.isLetter())
        {
            char16_t shiftedLetter = letter.unicode() + m_shifts;
            if (shiftedLetter > 0x007A) // Handles 'z'
            {
                char16_t diff = shiftedLetter - 0x007A;
                shiftedLetter = 0x0060 + diff;
            }
            else if (shiftedLetter < 0x0061) // Handles 'a'
            {
                char16_t diff = 0x0061 - shiftedLetter;
                shiftedLetter = 0x007B - diff;
            }
            m_cypherText += shiftedLetter;
        }
        else
        {
            m_cypherText += " ";
        }
    }
}
