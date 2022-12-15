let student = (imie, nazwisko, stypendium) => {
    return {imie:imie, nazwisko:nazwisko, stypendium:stypendium};
}

s1 = student("Maciej", "Bujnowski", 432)
s2 = student("Maciej", "Naparty", 435)
s3 = student("Maciej", "Choraś", 534)

s3.nazwisko = "Kowalski";

console.log(`${s3.imie} ${s3.nazwisko}`);