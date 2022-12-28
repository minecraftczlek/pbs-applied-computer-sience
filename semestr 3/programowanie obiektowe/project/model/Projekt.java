package com.project.model;

import java.time.LocalDate;
import java.time.LocalDateTime;

public class Projekt {

		private Integer projektId;
		private String nazwa;
		private String opis;
		private LocalDateTime dataczasUtworzenia;
		private LocalDate dataOddania;
		
		public Projekt () {}

		public Projekt(Integer projektId, String nazwa, String opis, LocalDateTime dataczasUtworzenia,
				LocalDate dataOddania) {
			this.projektId = projektId;
			this.nazwa = nazwa;
			this.opis = opis;
			this.dataczasUtworzenia = dataczasUtworzenia;
			this.dataOddania = dataOddania;
		}

		public Projekt(String nazwa, String opis, LocalDateTime dataczasUtworzenia, LocalDate dataOddania) {
			this.nazwa = nazwa;
			this.opis = opis;
			this.dataczasUtworzenia = dataczasUtworzenia;
			this.dataOddania = dataOddania;
		}

		public Integer getProjektId() {
			return projektId;
		}

		public void setProjektId(Integer projektId) {
			this.projektId = projektId;
		}

		public String getNazwa() {
			return nazwa;
		}

		public void setNazwa(String nazwa) {
			this.nazwa = nazwa;
		}

		public String getOpis() {
			return opis;
		}

		public void setOpis(String opis) {
			this.opis = opis;
		}

		public LocalDateTime getDataczasUtworzenia() {
			return dataczasUtworzenia;
		}

		public void setDataczasUtworzenia(LocalDateTime dataczasUtworzenia) {
			this.dataczasUtworzenia = dataczasUtworzenia;
		}

		public LocalDate getDataOddania() {
			return dataOddania;
		}

		public void setDataOddania(LocalDate dataOddania) {
			this.dataOddania = dataOddania;
		}
		
		
		
}
