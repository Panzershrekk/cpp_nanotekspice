using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class buttonSc : MonoBehaviour {
	bool state = false;
	GameObject li = null;
	// Use this for initialization
	void Start () {
		
	}
	
	// Update is called once per frame
	void Update () {
		if (li != null) {
			this.GetComponent<LineRenderer> ().enabled = true;
			this.GetComponent<LineRenderer> ().startWidth = 0.1f;
			this.GetComponent<LineRenderer> ().endWidth = 0.1f;
			this.GetComponent<LineRenderer> ().SetPosition (0, this.transform.position);
			this.GetComponent<LineRenderer> ().SetPosition (1, li.transform.position);
			//CHECK SI C'EST LA LAMPE
			if (li.name.Contains("light") != true)
				li.GetComponentInParent<door> ().setBool (li, state);
			//else
			//	li.GetComponentInParent<door> ().setBool (li, state);
		}
		else
			this.GetComponent<LineRenderer> ().enabled = false;
	}

	public void setLiaison(GameObject obj)
	{
		li = obj;
	}

	public void resetLi()
	{
		li = null;
	}

	public GameObject getLi()
	{
		return (li);
	}

	public void setState(bool s)
	{
		state = s;
	}

	public bool retState()
	{
		return (state);
	}

	public void setInput()
	{
		if (state == false) {
			this.transform.Find ("press").Translate (Vector3.down * 0.3f);
			state = true;
		} else {
			this.transform.Find ("press").Translate (Vector3.up * 0.3f);
			state = false;
		}
	}
}
	