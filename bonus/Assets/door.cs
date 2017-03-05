using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class door : MonoBehaviour {
	bool gate1 = false;
	bool gate2 = false;
	bool isLi1 = false;
	bool isLi2 = false;
	bool endGate = false;
	bool good = false;
	public bool cas1;
	public bool cas2;
	public bool cas3;
	public bool cas4;
	public bool cas5 = false;
	void Update () {
		if (good == true) {
			Vector3 tmp;
			tmp = this.transform.Find ("press (3)").transform.position;
			if (cas5 == true) {
				if (gate1 == true)
					tmp.y = 0.95f;
				else
					tmp.y = 0.69f;
				if (gate1 == true)
					this.transform.Find ("press (3)").GetComponent<buttonSc> ().setState (false);
				else
					this.transform.Find ("press (3)").GetComponent<buttonSc> ().setState (true);
				
			}
			else if (gate1 == false && gate2 == false) {
				if (cas1 == true)
					tmp.y = 0.69f;
				else
					tmp.y = 0.95f;
				this.transform.Find ("press (3)").GetComponent<buttonSc> ().setState (cas1);
			} else if (gate1 == false && gate2 == true) {
				if (cas2 == true)
					tmp.y = 0.69f;
				else
					tmp.y = 0.95f;
				this.transform.Find ("press (3)").GetComponent<buttonSc> ().setState (cas2);

			} else if (gate1 == true && gate2 == false) {
				if (cas3 == true)
					tmp.y = 0.69f;
				else
					tmp.y = 0.95f;
				this.transform.Find ("press (3)").GetComponent<buttonSc> ().setState (cas3);

			} else if (gate1 == true && gate2 == true) {
				if (cas4 == true)
					tmp.y = 0.69f;
				else
					tmp.y = 0.95f;
				this.transform.Find ("press (3)").GetComponent<buttonSc> ().setState (cas4);

			}
			this.transform.Find ("press (3)").transform.position = tmp;
		}
	}

	public void setGood(bool state)
	{
		good = state;
	}

	public void setFLi(string name)
	{
		if (name == "press (1)") {
			isLi1 = false;
		} else if (name == "press (2)")
			isLi2 = false;
	}

	public void setLi(string name)
	{
		if (name == "press (1)") {
			isLi1 = true;
		} else if (name == "press (2)")
			isLi2 = true;
		if (cas5 == true) {
			if (isLi1 == true) {
				this.transform.Find ("txtNb").GetComponent<TextMesh> ().color = Color.green;
				this.transform.Find ("txtNb").GetComponent<TextMesh> ().text = "1/1";
				this.transform.Find ("txtInfo").GetComponent<TextMesh> ().color = Color.green;
				this.transform.Find ("txtInfo").GetComponent<TextMesh> ().text = "Liaison correct";

			} else {
				this.transform.Find ("txtNb").GetComponent<TextMesh> ().color = Color.red;
				this.transform.Find ("txtNb").GetComponent<TextMesh> ().text = "0/1";
				this.transform.Find ("txtInfo").GetComponent<TextMesh> ().color = Color.red;
				this.transform.Find ("txtInfo").GetComponent<TextMesh> ().text = "Attente de liaison";	
			}
		} else {
			if (isLi1 == true && isLi2 == true) {
				this.transform.Find ("txtNb").GetComponent<TextMesh> ().color = Color.green;
				this.transform.Find ("txtNb").GetComponent<TextMesh> ().text = "2/2";
				this.transform.Find ("txtInfo").GetComponent<TextMesh> ().color = Color.green;
				this.transform.Find ("txtInfo").GetComponent<TextMesh> ().text = "Liaison correct";
			} else if (isLi1 == false && isLi2 == false) {
				this.transform.Find ("txtNb").GetComponent<TextMesh> ().color = Color.red;
				this.transform.Find ("txtNb").GetComponent<TextMesh> ().text = "0/2";
				this.transform.Find ("txtInfo").GetComponent<TextMesh> ().color = Color.red;
				this.transform.Find ("txtInfo").GetComponent<TextMesh> ().text = "Attente de liaison";
			} else {
				this.transform.Find ("txtNb").GetComponent<TextMesh> ().color = Color.red;
				this.transform.Find ("txtNb").GetComponent<TextMesh> ().text = "1/2";
				this.transform.Find ("txtInfo").GetComponent<TextMesh> ().color = Color.red;
				this.transform.Find ("txtInfo").GetComponent<TextMesh> ().text = "Attente de liaison";	
			}
		}
	}

	public bool retLi(string name)
	{

		if (name == "press (1)") {
			return (isLi1);
		} else
			return (isLi2);
	}

	public void setBool(GameObject obj, bool etat)
	{
		Vector3 tmp;
		if (obj.name == "press (1)")
			gate1 = etat;
		else
			gate2 = etat;
		tmp = obj.transform.position;
		if (etat == true) {
			tmp.y = 0.69f;
			obj.transform.position = tmp;
		} else {
			tmp.y = 0.87f;
			obj.transform.position = tmp;
		}
	}
}
